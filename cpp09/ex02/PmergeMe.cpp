#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): struggle(-1)
{

}

PmergeMe::~PmergeMe()
{

}


void	PmergeMe::print_list()
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::parse_args(std::string& s)
{
	if (s.find_first_not_of("0123456789 ") != std::string::npos)
		throw error("Invalid character");

	std::stringstream	ss(s);
	int					nbr;
	while (ss >> nbr)
	{
		if (std::find(vect.begin(), vect.end(), nbr) != vect.end())
			throw error("Duplicate numbers");
		else
		{
			vect.push_back(nbr);
			deque.push_back(nbr);
		}
	}
}

int		JacobsthalSequence(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return JacobsthalSequence(n - 1) + 2 * JacobsthalSequence(n - 2);
}

int		binary_search(std::vector<int>& main, int val, int low, int high)
{
	if (high <= low)
		return (main[low] < val) ? low + 1 : low;

	int mid = (low + high) / 2;

	if (main[mid] == val)
		return mid + 1;
	else if (val < main[mid])
		return binary_search(main, val, low, mid - 1);
	else
		return binary_search(main, val, mid + 1, high);
}

void	binary_insertion(std::vector<int>& main, int val, int start, int end)
{
	int	loc = binary_search(main, val, start, end);
	main.insert(main.begin() + loc, val);
}


void	PmergeMe::sort_pairs()
{
	if (vect.size() % 2 != 0)
	{
		struggle = vect.back();
		std::cout << "hhhhhhhhhhh" << std::endl;
		vect.pop_back();
	}

	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					pend;

	for (size_t i = 0; i < vect.size(); i += 2)
	{
		if (vect[i] < vect[i + 1])
			std::swap(vect[i], vect[i + 1]);
	}

	for (size_t i = 0; i < vect.size(); i += 2)
		pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
	
	
	std::sort(pairs.begin(), pairs.end());
	vect.clear();
	for (size_t i = 0; i < pairs.size(); i++)
		vect.push_back(pairs[i].first);
	
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);
	

	vect.insert(vect.begin(), pairs[0].second);
	int i = 2;
	while (!pend.empty())
	{
		int batch = JacobsthalSequence(i + 1) - JacobsthalSequence(i);
		if (pend.size() < static_cast<size_t> (batch))
			batch = pend.size();
		while (batch--)
		{
			binary_insertion(vect, pend[batch], 0, std::distance(vect.begin(), std::lower_bound(vect.begin(), vect.end(), pend[batch])) - 1);
			pend.erase(pend.begin() + batch);
		}
		i++;
	}
	if (struggle != -1)
	{
		binary_insertion(vect, struggle, 0, vect.size() - 1);
		// std::cout << "qqqqqqqqqq" << std::endl;
	}
}