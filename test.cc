//        Alpha Vantage API KEY = 9CDYVVKCZIM1S15W

#include "stock.h"
#include "portfolio.h"
#include <cctype>
#include <vector>

int main() {
  stocks::Stock a("TWTR", 9, 36.77, 0.51, 2.75, 12.98, 63.17, 134.97, -21.32, 6.4);
  stocks::Stock b("AAPL", 4, 178.15, -0.35, -1.19, 3.36, 2.29, 28.89, 211.81, 1.0);
  stocks::Stock c("NFLX", 3, 318.76, -0.82, -4.48, 14.36, 66.72, 119.15, 1130.19, 1.6);
  stocks::Stock d("FB", 5, 185.20, 0.67, -0.08, 3.47, 2.31, 32.56,  602.31, 1.2);
  stocks::Stock e("BAC", 1, 32.21, 0.22, -1.5, 1.03, 10.38, 33.21, 177.3, 1.3);
  stocks::Stock f("DIS", 2, 103.0, -0.36, -1.64, -2.08, -7.9, -6.66, 93.04, 1.4);
  stocks::Stock g("INTC", 10, 51.25, 0.57, -1.18, 11.86, 14.28, 48.94, 182.13);
  stocks::Stock h("KO", 8, 43.54, -0.48, -3.12, -3.61, -4.93, 6.9, 31.97, 2.2);
  return 0;
}
