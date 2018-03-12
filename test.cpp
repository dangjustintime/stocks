//        Alpha Vantage API KEY = 9CDYVVKCZIM1S15W

#include "stock.h"
#include "portfolio.h"
#include <iostream>
#include <cctype>
#include <vector>

int main() {
          Stock a("TWTR", 0.51, 2.75, 12.98, 63.17, 134.97, -21.32);
          Stock b;

          std::cout << "------STOCK A ------" << std::endl;
          a.print();
          std::cout << "------STOCK B ------" << std::endl;
          b.print();

          b = std::move(a);

          std::cout << "------STOCK A ------" << std::endl;
          a.print();
          std::cout << "------STOCK B ------" << std::endl;
          b.print();

}
