//        Alpha Vantage API KEY = 9CDYVVKCZIM1S15W

#include "stock.h"
#include "portfolio.h"
#include <iostream>
#include <cctype>
#include <vector>

int main() {
          Stock a("TWTR", 0.51, 2.75, 12.98, 63.17, 134.97, -21.32);
          Stock b("MSFT", -0.59, -0.43, 6.03, 10.59, 48.48, 283.08);
          Stock c("AAPL", -0.85, 1.69, 10.26, 3.26, 30.12, 212.54);
          Stock d("NFLX", 1.79, -0.17, 25.02, 69.64, 123.07, 1141.38);
          Stock e("FB", 1.27, 0.28, 4.78, 2.79, 32.11, 597.8);
          Stock f("BAC", 0.31, 0.16, 4.26, 11.94, 30.1, 177.56);
          Stock g("DIS", 0.09, 0.00, 1.32, -7.14, -6.07, 94.89);
          Stock h("INTC", 0.15, 0.77, 16.98, 21, 53.45, 187.14);
}
