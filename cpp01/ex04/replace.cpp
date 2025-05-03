#include "replace.hpp"

void	replace(std::string filename, std::string s1, std::string s2)
{
	std::string	line;
    size_t		pos;

	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Invalid input: empty argument" << std::endl;
		exit (1);
	}

    std::ifstream infile(filename.c_str());

	if (!infile.is_open())
	{
        std::cout << "can't open the file " << filename << std::endl;
		exit (1);
	}

	std::ofstream outfile((filename + ".replace").c_str());

	if (!outfile.is_open())
	{
        std::cout << "can't open the file " << filename + ".replace" << std::endl;
		infile.close();
		exit (1);
	}

    while (std::getline(infile, line))
    {
		while (1)
		{
			pos = line.find(s1);
			if (pos == std::string::npos)
				break;
			else
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
			}
		}
		outfile << line;
		outfile << std::endl;
    }
}