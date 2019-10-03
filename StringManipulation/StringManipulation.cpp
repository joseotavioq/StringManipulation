#include <iostream>
#include "crt.h"

int main()
{
    std::cout << "[TOLOWER]\n";
	std::cout << "mytolower('J') = " << mytolower('J') << "\n";
	std::cout << "mytolower('o') = " << mytolower('o') << "\n";
	std::cout << "mytolower('S') = " << mytolower('S') << "\n";
	std::cout << "mytolower('e') = " << mytolower('e') << "\n\n";

	std::cout << "[TOUPPER]\n";
	std::cout << "mytoupper('J') = " << mytoupper('J') << "\n";
	std::cout << "mytoupper('o') = " << mytoupper('o') << "\n";
	std::cout << "mytoupper('S') = " << mytoupper('S') << "\n";
	std::cout << "mytoupper('e') = " << mytoupper('e') << "\n\n";
}