#include "stock.h"
//#include "portfolio.h"
#include <iostream>
#include <cctype>
#include <vector>

int main() {
	//default constructor
	Stock a;
	std::cout << a;	
	Stock b("TSLA", 335.10, 1.27, -5.21, -0.85, 10.96, 35.17, 762.1);
	std::cout << b;

	//copy constructor

	//move constructor

	//assignment operator

	//assignment operator (move version)

	//getters and setters

	return 0;
}
