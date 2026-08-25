#include "PmergeMe.hpp"

PmergeMe::PmergeMe(PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	(void)other;
	return *this;
}
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

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
	(void)ac;
	this->raw = convert_av_to_raw(av);
}

// 야콥스탈 수열(0, 1, 1, 3, 5, 11, ...)을 이용해 pendant 삽입 순서를 만든다.
// b1은 항상 먼저 삽입되므로, 반환되는 순서는 b3 b2, b5 b4, b11 ... b6 형태 (1-based index)
static std::vector<size_t> build_insertion_order(size_t pendant_count)
{
	std::vector<size_t> order;
	if (pendant_count < 2)
		return order;

	size_t prev_jacob = 1;
	size_t j_a = 1, j_b = 1; // J(2)=1, J(3)=3, J(n)=J(n-1)+2*J(n-2)
	while (prev_jacob < pendant_count)
	{
		size_t current_jacob = j_b + 2 * j_a;
		size_t end_point = std::min(current_jacob, pendant_count);

		for (size_t k = end_point; k > prev_jacob; --k)
			order.push_back(k);
		prev_jacob = current_jacob;
		j_a = j_b;
		j_b = current_jacob;
	}
	return order;
}

template <typename Container>
static void merge_insertion_sort(Container &v)
{
	if (v.size() <= 1)
		return;

	// leftover (홀수 개일 때 남는 요소)
	bool has_leftover = v.size() % 2 != 0;
	unsigned int leftover = 0;
	if (has_leftover)
		leftover = v[v.size() - 1];

	// 1. 쌍 만들기 (first = 큰 값, second = 작은 값)
	std::vector<t_pair> pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] < v[i + 1])
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
		else
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}

	// 2. main(큰 값)들만 추출해서 재귀 정렬
	Container mains;
	for (size_t i = 0; i < pairs.size(); ++i)
		mains.push_back(pairs[i].first);
	merge_insertion_sort(mains);

	// 3. 정렬된 main 순서에 맞춰 pendant(작은 값) 재배열 (중복 값은 used로 구분)
	std::vector<unsigned int> pendants;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < mains.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].first == mains[i])
			{
				pendants.push_back(pairs[j].second);
				used[j] = true;
				break;
			}
		}
	}

	// 4. main chain 구성: b1은 a1보다 작거나 같으므로 무조건 맨 앞
	Container result;
	result.push_back(pendants[0]);
	for (size_t i = 0; i < mains.size(); ++i)
		result.push_back(mains[i]);

	// 5. 나머지 pendant를 야콥스탈 순서로 이진 삽입
	std::vector<size_t> order = build_insertion_order(pendants.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		unsigned int element = pendants[order[i] - 1];
		typename Container::iterator pos =
			std::lower_bound(result.begin(), result.end(), element);
		result.insert(pos, element);
	}

	// 6. leftover 삽입
	if (has_leftover)
	{
		typename Container::iterator pos =
			std::lower_bound(result.begin(), result.end(), leftover);
		result.insert(pos, leftover);
	}

	v = result;
}

void PmergeMe::sort_vector()
{
	this->vec.assign(this->raw.begin(), this->raw.end());
	merge_insertion_sort(this->vec);
}

void PmergeMe::sort_deque()
{
	this->deq.assign(this->raw.begin(), this->raw.end());
	merge_insertion_sort(this->deq);
}

static void print_vec(const std::vector<unsigned int> &v)
{
	for (std::vector<unsigned int>::const_iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	print_vec(this->raw);

	clock_t start_vec = clock();
	sort_vector();
	clock_t finish_vec = clock();

	clock_t start_deq = clock();
	sort_deque();
	clock_t finish_deq = clock();

	std::cout << "After:  ";
	print_vec(this->vec);

	double time_vec = static_cast<double>(finish_vec - start_vec) / CLOCKS_PER_SEC * 1000000.0;
	double time_deq = static_cast<double>(finish_deq - start_deq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << time_deq << " us" << std::endl;
}
