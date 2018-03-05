#include "stock.h"
//#include "portfolio.h"
#include <iostream>
#include <cctype>
#include <vector>

int main() {
	//default constructor
	std::cout << "\n--------STOCK A--------" << std::endl;
	Stock a;
	std::cout << a;	
	std::cout << "\n--------STOCK B--------" << std::endl;
	Stock b("TSLA", 335.10, 1.27, -5.21, -0.85, 10.96, 35.17, 762.1);
	std::cout << b;

	//copy constructor
	std::cout << "\n--------STOCK C--------" << std::endl;
	Stock c(b);
	std::cout << c;
	
	//move constructor
	std::cout << "\n--------STOCK C--------" << std::endl;
	Stock d(std::move(c));
	c.print();
	std::cout << "\n--------STOCK D--------" << std::endl;
	d.print();
	
	//assignment operator


	//assignment operator (move version)

	//getters and setters

	return 0;
}
