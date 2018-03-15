//        Alpha Vantage API KEY = 9CDYVVKCZIM1S15W
/*
 *        TODO:
 *                  -fixed buyStock and sellStock in portfolio.h
 *                  -test all member functions in portfolio class
*/

#include "stock.h"
#include "portfolio.h"
#include <iostream>
#include <cctype>
#include <vector>

int main() {
          Stock a("TWTR", 1, 36.77, 0.51, 2.75, 12.98, 63.17, 134.97, -21.32, 6.4);
          Stock b("MSFT", 3, 93.85, -0.59, -0.43, 6.03, 10.59, 48.48, 283.08, 1.1);
          Stock c("AAPL", 1, 178.57, -0.85, 1.69, 10.26, 3.26, 30.12, 212.54, 7.0);
          Stock d("NFLX", 6, 321.66, 1.79, -0.17, 25.02, 69.64, 123.07, 1141.38, 8.2);
          Stock e("FB", 2, 184.01, 1.27, 0.28, 4.78, 2.79, 32.11, 597.8, 5.3);
          Stock f("BAC", 5, 32.24, 0.31, 0.16, 4.26, 11.94, 30.1, 177.56, 6.6);
          Stock g("DIS", 10, 103.99, 0.09, 0.00, 1.32, -7.14, -6.07, 94.89, 1.2);
         
          Portfolio p0;
          p0.addStock(a);
          p0.addStock(b);
          p0.addStock(c);
          p0.addStock(d);
          p0.setCashValue(600);
          p0.print();

          p0.buyStock(a);
          p0.print();

          return 0;
}
