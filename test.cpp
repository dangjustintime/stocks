//        Alpha Vantage API KEY = 9CDYVVKCZIM1S15W

#include "stock.h"
//#include "portfolio.h"
#include <cctype>
#include <vector>

using namespace stocks;

int main() {
	Stock a("TWTR", 9, 36.77, 0.51, 2.75, 12.98, 63.17, 134.97, -21.32, 6.4);
	a.print();
	Stock b = --a;
	a.print();
	b.print();
	return 0;
}
