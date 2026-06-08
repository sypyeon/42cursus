#include "PmergeMe.hpp"

PmergeMe::PmergeMe(PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	(void)other;
	return *this;
}
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

static std::vector<unsigned int> gen_jacobsthal(int n)
{
	std::vector<unsigned int> jacobsthal;
	unsigned int limit = n / 2 + 1;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	unsigned int j = 1;
	while (jacobsthal.back() < limit)
	{
		int i = jacobsthal.size();
		j = jacobsthal.at(i - 1) + (2 * jacobsthal.at(i - 2));
		jacobsthal.push_back(j);
	}
	return jacobsthal;
}

static std::vector<unsigned int> convert_av_to_raw(char **av)
{
	std::vector<unsigned int> vec;

	for (int i = 1; av[i]; ++i)
	{
		std::string str(av[i]);
		if (str.empty())
			throw std::runtime_error("empty argument");
		for (size_t j = 0; j < str.length(); ++j)
		{
			if (!std::isdigit(str[j]))
				throw std::runtime_error("not a positive integer");
		}
		long val = std::atol(av[i]);
		if (val < 0 || val > UINT_MAX)
			throw std::runtime_error("out of range");
		vec.push_back(static_cast<unsigned int>(val));
	}
	return vec;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	this->jacobsthal = gen_jacobsthal(ac);
	this->raw = convert_av_to_raw(av);
}

void recursive_sort(std::vector<unsigned int> &v)
{
	if (v.size() <= 1)
		return;

    // leftover
    bool has_leftover = v.size() % 2 != 0;
    unsigned int leftover = 0;
    if (has_leftover)
        leftover = v.back();

    // 1. 쌍 만들기
    std::vector<t_pair> pairs;
    for (size_t i = 0; i < v.size() - has_leftover; i += 2)
    {
        if (v[i] < v[i + 1])
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        else
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }

    // 2. main만 추출
    std::vector<unsigned int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger_elements.push_back(pairs[i].first);

    // 3. 재귀 — main들을 정렬
    recursive_sort(larger_elements);
}

void PmergeMe::sort_vector()
{
	std::vector<unsigned int> small; // Pendants
	unsigned int leftover = 0;
	bool has_leftover = false;

	// cut off residual element
	std::vector<unsigned int> temp_raw = this->raw;
	if (temp_raw.size() % 2 != 0)
	{
		leftover = temp_raw.back();
		temp_raw.pop_back();
		has_leftover = true;
	}

	// pairing elements
	std::vector<t_pair> pairs;
	for (size_t i = 0; i < temp_raw.size(); i += 2)
	{
		unsigned int a = temp_raw[i];
		unsigned int b = temp_raw[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	// 큰 값(first)을 기준으로 쌍들을 정렬 (관계 유지)
	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].first > pairs[j].first)
				std::swap(pairs[i], pairs[j]);
		}
	}

	// 2. Main Chain(vec)과 Pendants(small) 구성
	for (size_t i = 0; i < pairs.size(); i++)
	{
		vec.push_back(pairs[i].first);
		small.push_back(pairs[i].second);
	}

	// 3. 첫 번째 작은 값은 무조건 맨 앞 (pairs[0].first > pairs[0].second 이므로 안전)
	vec.insert(vec.begin(), small[0]);

	// 4. 야콥스탈 순서에 따른 이진 삽입
	std::vector<size_t> insertion_order;
	size_t pendant_size = small.size();
	size_t j_idx = 3;
	size_t last_jacob = 1;

	while (insertion_order.size() < pendant_size - 1)
	{
		size_t current_jacob = (j_idx < jacobsthal.size()) ? jacobsthal[j_idx] : pendant_size;
		size_t end_point = std::min(current_jacob, pendant_size);

		for (size_t k = end_point; k > last_jacob; --k)
		{
			if (k > 1)
				insertion_order.push_back(k); // 1번은 이미 삽입됨
		}
		last_jacob = current_jacob;
		j_idx++;
		if (last_jacob >= pendant_size)
			break;
	}

	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		unsigned int element_to_insert = small[insertion_order[i] - 1];
		std::vector<unsigned int>::iterator insert_pos =
			std::lower_bound(vec.begin(), vec.end(), element_to_insert);
		vec.insert(insert_pos, element_to_insert);
	}

	// 5. 남은 홀수 요소 삽입
	if (has_leftover)
	{
		std::vector<unsigned int>::iterator insert_pos =
			std::lower_bound(vec.begin(), vec.end(), leftover);
		vec.insert(insert_pos, leftover);
	}
}

void PmergeMe::sort_deque()
{
}

static void print_vec(std::vector<unsigned int> v)
{
	for (std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::run()
{
	clock_t start_vec = clock();
	sort_vector();
	clock_t finish_vec = clock();
	print_vec(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << finish_vec - start_vec << " us" << std::endl;
}
