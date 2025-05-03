#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
	{
        std::cout << "Invalid number of args\n";
		exit (1);
	}
	replace(argv[1], argv[2], argv[3]);
    return 0;
}