#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): struggle(-1)
{
}

PmergeMe::PmergeMe(const PmergeMe& other):vect(other.vect), deque(other.deque),	struggle(other.struggle)
{
}

PmergeMe& PmergeMe::operator= (const PmergeMe& other)
{
	if (this != &other)
	{
		vect = other.vect;
		deque = other.deque;
		struggle = other.struggle;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::print_list(std::string str, int container_flag)
{
	std::cout << str;
	if (container_flag == VECTOR)
		for (size_t i = 0; i < vect.size(); i++)
			std::cout << vect[i] << " ";
	else if (container_flag == DEQUE)
		for (size_t i = 0; i < deque.size(); i++)
			std::cout << deque[i] << " ";

	std::cout << std::endl;
}

void	PmergeMe::parse_args(char** args)
{

	for (size_t i = 1; args[i]; i++)
	{
		std::string s(args[i]);
		if (s.find_first_not_of("0123456789") != std::string::npos)
			throw error("Error: Invalid character or number");
		int	nbr = atoi(args[i]);
		if (std::find(vect.begin(), vect.end(), nbr) != vect.end())
			throw error("Error: Duplicate numbers");
		else
		{
			vect.push_back(nbr);
			deque.push_back(nbr);
		}
	}
	
	if (vect.size() == 1)
		throw error("Error: Please insert more than one integer");
}

int		JacobsthalSequence(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return JacobsthalSequence(n - 1) + 2 * JacobsthalSequence(n - 2);
}

int		PmergeMe::binary_search(int container_flag, int val, int low, int high)
{
	int mid = (low + high) / 2;

	if (container_flag == VECTOR)
	{
		if (high <= low)
			return (vect[low] < val) ? low + 1 : low;
		else if (vect[mid] == val)
			return mid + 1;
		else if (val < vect[mid])
			return binary_search(VECTOR, val, low, mid - 1);
		else
			return binary_search(VECTOR, val, mid + 1, high);
	}
	else
	{
		if (high <= low)
			return (deque[low] < val) ? low + 1 : low;
		else if (deque[mid] == val)
			return mid + 1;
		else if (val < deque[mid])
			return binary_search(DEQUE, val, low, mid - 1);
		else
			return binary_search(DEQUE, val, mid + 1, high);
	}
}

void	PmergeMe::binary_insertion(int container_flag, int val, int start, int end)
{
	if (container_flag == VECTOR)
	{
		int	loc = binary_search(VECTOR, val, start, end);
		vect.insert(vect.begin() + loc, val);
	}
	else if (container_flag == DEQUE)
	{
		int	loc = binary_search(DEQUE, val, start, end);
		deque.insert(deque.begin() + loc, val);
	}
}

long long	calcul_time(struct timespec& start, struct timespec& end)
{
	long long sec  = end.tv_sec  - start.tv_sec;
    long long nsec = end.tv_nsec - start.tv_nsec;

    if (nsec < 0) {
        sec  -= 1;
        nsec += 1000000000LL;
    }
    return sec * 1000000LL + nsec / 1000LL;
}

void	PmergeMe::sort_vect()
{
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					pend;
	struct timespec						start, end;

	this->print_list("Before:  ", VECTOR);

	clock_gettime(CLOCK_MONOTONIC, &start);
	//Handling the extra number if the number of elements is odd
	if (vect.size() % 2 != 0)
	{
		struggle = vect.back();
		vect.pop_back();
	}

	//Sorting the pairs
	for (size_t i = 0; i < vect.size(); i += 2)
	{
		if (vect[i] < vect[i + 1])
			std::swap(vect[i], vect[i + 1]);
	}

	for (size_t i = 0; i < vect.size(); i += 2)
		pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
	std::sort(pairs.begin(), pairs.end());

	vect.clear();
	// Creating the main list
	for (size_t i = 0; i < pairs.size(); i++)
		vect.push_back(pairs[i].first);
	
	// Creating the pend list
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	//Inserting the first element from the pend list
	vect.insert(vect.begin(), pairs[0].second);
	int i = 2;

	//Inserting the pend list
	while (!pend.empty())
	{
		int batch = JacobsthalSequence(i + 1) - JacobsthalSequence(i);
		if (pend.size() < static_cast<size_t> (batch))
			batch = pend.size();
		while (batch--)
		{
			int end_index = std::distance(vect.begin(), std::lower_bound(vect.begin(), vect.end(), pend[batch])) - 1;
			binary_insertion(VECTOR, pend[batch], 0, end_index);
			pend.erase(pend.begin() + batch);
		}
		i++;
	}

	//Inserting the extra element
	if (struggle != -1)
		binary_insertion(VECTOR, struggle, 0, vect.size() - 1);
		
	clock_gettime(CLOCK_MONOTONIC, &end);
	this->print_list("After:  ", VECTOR);
	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : " << calcul_time(start, end) << "us" << std::endl;
}



void	PmergeMe::sort_deque()
{
	std::deque<std::pair<int, int> >	pairs;
	std::deque<int>						pend;
	struct timespec						start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	//Handling the extra number if the number of elements is odd
	if (deque.size() % 2 != 0)
	{
		struggle = deque.back();
		deque.pop_back();
	}

	//Sorting the pairs
	for (size_t i = 0; i < deque.size(); i += 2)
	{
		if (deque[i] < deque[i + 1])
			std::swap(deque[i], deque[i + 1]);
	}

	for (size_t i = 0; i < deque.size(); i += 2)
		pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
	
	std::sort(pairs.begin(), pairs.end());

	deque.clear();
	// Creating the main list
	for (size_t i = 0; i < pairs.size(); i++)
		deque.push_back(pairs[i].first);
	
	// Creating the pend list
	for (size_t i = 1; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);
	
	//Inserting the first element from the pend list
	deque.insert(deque.begin(), pairs[0].second);
	int i = 2;

	//Inserting the pend list
	while (!pend.empty())
	{
		int batch = JacobsthalSequence(i + 1) - JacobsthalSequence(i);
		if (pend.size() < static_cast<size_t> (batch))
			batch = pend.size();
		while (batch--)
		{
			int end_index = std::distance(deque.begin(), std::lower_bound(deque.begin(), deque.end(), pend[batch])) - 1;
			binary_insertion(DEQUE, pend[batch], 0, end_index);
			pend.erase(pend.begin() + batch);
		}
		i++;
	}
	
	//Inserting the extra element
	if (struggle != -1)
		binary_insertion(DEQUE, struggle, 0, deque.size() - 1);

	clock_gettime(CLOCK_MONOTONIC, &end);
	std::cout << "Time to process a range of " << vect.size() << " elements with std::deque  : " << calcul_time(start, end) << "us" << std::endl;
}








// void	PmergeMe::parse_args(std::string& s)
// {
// 	if (s.find_first_not_of("0123456789 ") != std::string::npos)
// 		throw error("Invalid character");
// 	std::stringstream	ss(s);
// 	int					nbr;
// 	while (ss >> nbr)				
// 	{
// 		if (std::find(vect.begin(), vect.end(), nbr) != vect.end())
// 			throw error("Duplicate numbers");
// 		else
// 		{
// 			vect.push_back(nbr);
// 			deque.push_back(nbr);
// 		}
// 	}
// 	if (vect.size() == 1)
// 		throw error("Please insert more than one integer");
// }