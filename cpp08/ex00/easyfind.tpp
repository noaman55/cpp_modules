
template <typename T>
typename T::iterator	easyfind(T& container, int n)
{
	typename T::iterator it = find(container.begin(), container.end(), n);

	if (it != container.end())
		return it;
	else
		throw error();

}
