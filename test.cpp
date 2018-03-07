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
          Stock e("KO", 43.50, 0.09, -0.84, -6.75, -6.03, 7.05, 29.66);
          e.print();
          Stock f = e;
          std::cout << "STOCK F" << std::endl;
          f.print();

	//assignment operator (move version)
          b = std::move(e);
          std::cout << "STOCK B" << std::endl;
          b.print();
          std::cout << "STOCK E" << std::endl;
          e.print();

	//getters and setters
	std::cout << "\n\n\n\n--------GETTERS--------" << std::endl;
          b.print();
          std::cout << "getName() = " << b.getName() << std::endl;
          std::cout << "getPrice() = " << b.getPrice() << std::endl;
          std::cout << "getDailyRate() = " << b.getDailyRate() << std::endl;
          std::cout << "getWeeklyRate() = " << b.getWeeklyRate() << std::endl;
          std::cout << "getMonthlyRate() = " << b.getMonthlyRate() << std::endl;
          std::cout << "getThreeMonthRate() = " << b.getThreeMonthRate() << std::endl;
          std::cout << "getYearlyRate() = " << b.getYearlyRate() << std::endl;
          std::cout << "getDividend() = " << b.getDividend() << std::endl;
          
          
	std::cout << "\n\n\n\n--------SETTERS--------" << std::endl;
          b.setName("TWTR");
          b.setPrice(33.62);
          b.setDailyRate(-0.43);
          b.setWeeklyRate(6.73);
          b.setMonthlyRate(32.52);
          b.setThreeMonthRate(59.64);
          b.setYearlyRate(116.62);
          b.setGeneralRate(-25.45);
          b.setDividend(99.99);


          std::cout << "getName() = " << b.getName() << std::endl;
          std::cout << "getPrice() = " << b.getPrice() << std::endl;
          std::cout << "getDailyRate() = " << b.getDailyRate() << std::endl;
          std::cout << "getWeeklyRate() = " << b.getWeeklyRate() << std::endl;
          std::cout << "getMonthlyRate() = " << b.getMonthlyRate() << std::endl;
          std::cout << "getThreeMonthRate() = " << b.getThreeMonthRate() << std::endl;
          std::cout << "getYearlyRate() = " << b.getYearlyRate() << std::endl;
          std::cout << "getDividend() = " << b.getDividend() << std::endl;
          
	return 0;
          
	return 0;
}
