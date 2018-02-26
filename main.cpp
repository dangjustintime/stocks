#include "portfolio.h"
#include <iostream>
#include <cctype>
#include <vector>

//function prototypes
void printMenu();

int main() {
	char ch;
	do {
		printMenu();
		std::cin.get(ch);
		std::tolower(ch);
		switch(ch) {
			case 'p':
				break;
			case 'b':
				break;
			case 's':
				break;
			case 'x':
				break;
			default:
				break;
		}
	} while(ch != 'x');
	return 0;
}

//function definitions
void printMenu() {
	std::cout << "\n\n\n----------------------------------------" << std::endl;
	std::cout << "\tP - Portfolio" << std::endl;
	std::cout << "\tB - Buy stock" << std::endl;
	std::cout << "\tS - Sell stock" << std::endl;
	std::cout << "\tX - Exit" << std::endl;	
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Enter: ";
};
