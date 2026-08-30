#include "PmergeMe.hpp"

// Orthodox Canonical Form
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	(void)other;
	return *this;
}
PmergeMe::~PmergeMe() {}

// Parsing & Helper Utility
static std::vector<uint> parse_arguments(char **av)
{
	std::vector<uint> numbers;

	for (int i = 1; av[i]; ++i)
	{
		std::string arg(av[i]);
		if (arg.empty())
			throw std::runtime_error("Empty argument");

		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (!std::isdigit(arg[j]))
				throw std::runtime_error("Non-digit character");
		}

		long val = std::atol(av[i]);
		if (val < 0 || val > UINT_MAX)
			throw std::runtime_error("Out of range");

		numbers.push_back(static_cast<uint>(val));
	}
	return numbers;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	(void)ac;
	this->raw = parse_arguments(av);
}

// Jacobsthal 수열 기반으로 Insert order 순서를 생성
static std::vector<size_t> make_jacobsthal_order(size_t count)
{
	std::vector<size_t> order;
	if (count < 2)
		return order;

	size_t prev = 1;
	size_t j_prev = 1;
	size_t j_curr = 1;

	while (prev < count)
	{
		size_t next_jacob = j_curr + 2 * j_prev;
		size_t limit = std::min(next_jacob, count);

		for (size_t k = limit; k > prev; --k)
			order.push_back(k);

		prev = next_jacob;
		j_prev = j_curr;
		j_curr = next_jacob;
	}
	return order;
}

// Comparison Helper
struct ByKey
{
	const std::vector<uint> &raw_data;

	explicit ByKey(const std::vector<uint> &data) : raw_data(data) {}
	bool operator()(uint idx1, uint idx2) const
	{
		return raw_data[idx1] < raw_data[idx2];
	}
};

// Merge-Insertion Algorithm Core
template <typename Container>
static void merge_insertion_sort(Container &elements, const std::vector<uint> &key)
{
	if (elements.size() <= 1)
		return;

	ByKey less(key);

	// 1. 홀수 개일 때 남는 요소 처리
	bool has_leftover = (elements.size() % 2 != 0);
	uint leftover = 0;
	if (has_leftover)
	{
		leftover = elements.back();
		elements.pop_back();
	}

	// 2. 페어링 (큰 값 -> main, 작은 값 -> partner)
	Container mains;
	std::vector<uint> partner(key.size(), 0);

	typename Container::iterator it = elements.begin();
	while (it != elements.end())
	{
		uint a = *it++;
		uint b = *it++;

		if (less(a, b))
			std::swap(a, b);

		mains.push_back(a);
		partner[a] = b;
	}

	// 3. Main 체인 재귀 정렬
	merge_insertion_sort(mains, key);

	// 4. Main 순서에 대응하는 Pendants 추출
	std::vector<uint> pendants;
	pendants.reserve(mains.size());
	for (typename Container::const_iterator mit = mains.begin(); mit != mains.end(); ++mit)
		pendants.push_back(partner[*mit]);

	// 5. Main Chain 기본 배치 (b1은 항상 맨 앞에 배치)
	Container main_chain;
	main_chain.push_back(pendants[0]);
	main_chain.insert(main_chain.end(), mains.begin(), mains.end());

	// 6. Jacobsthal 순서대로 Pendants 이진 삽입
	std::vector<size_t> order = make_jacobsthal_order(pendants.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		uint pendant = pendants[order[i] - 1];
		typename Container::iterator pos =
			std::lower_bound(main_chain.begin(), main_chain.end(), pendant, less);
		main_chain.insert(pos, pendant);
	}

	// 7. Leftover 삽입
	if (has_leftover)
	{
		typename Container::iterator pos =
			std::lower_bound(main_chain.begin(), main_chain.end(), leftover, less);
		main_chain.insert(pos, leftover);
	}

	elements = main_chain;
}

// Container Sort Wrapper
template <typename Container>
static void run_sort(Container &out, const std::vector<uint> &raw)
{
	Container index_list;
	for (uint i = 0; i < raw.size(); ++i)
		index_list.push_back(i);

	merge_insertion_sort(index_list, raw);

	out.clear();
	for (typename Container::const_iterator it = index_list.begin(); it != index_list.end(); ++it)
		out.push_back(raw[*it]);
}

void PmergeMe::sort_vector() { run_sort(this->vec, this->raw); }
void PmergeMe::sort_list() { run_sort(this->list, this->raw); }

// Output & Execution
static void print_elements(const std::vector<uint> &v)
{
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << "\n";
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	print_elements(this->raw);

	clock_t start_v = clock();
	sort_vector();
	clock_t end_v = clock();

	clock_t start_l = clock();
	sort_list();
	clock_t end_l = clock();

	std::cout << "After:  ";
	print_elements(this->vec);

	double time_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1e6;
	double time_l = static_cast<double>(end_l - start_l) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << time_v << " us\n";
	std::cout << "Time to process a range of " << list.size()
			  << " elements with std::list   : " << time_l << " us\n";
}