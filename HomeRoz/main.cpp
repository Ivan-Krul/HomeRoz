#include <iostream>

#include "queryhomeroz.h"
#include "Window.h"

int main()
{
	QueryHR query;
	std::string q;
	while (true)
	{
		std::cout << "#: ";
		std::getline(std::cin, q);
		if (q == "EXIT")
			break;
	}
	return 0;
}
