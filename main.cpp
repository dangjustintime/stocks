#include "stock.h"
#include "portfolio.h"
#include <iostream>
#include <cctype>

//function prototypes
void printMenu();
Stock createStock();

int main() {
          char menuChoice;
          Portfolio portfolio;
          while(ch != 'q') {
                    portfolio.print();
                    printMenu();
                    switch(menuChoice) {
                              //buy stock
                              case 'b':
                                      break;
                              //sell stock
                              case 's':
                                      break;
                              //add cash
                              case 'a':
                                      break;
                              //restart
                              case 'r':
                                      break;
                              //undo
                              case 'u':
                                      break;
                              //quit
                              case 'q':
                                      break;
                    }
          }
          return 0;
}

//definitions
void printMenu() {
          std::cout << "\n----------Main Menu----------" << std::endl;
          std::cout << "\tb - buy stock" << std::endl;
          std::cout << "\ts - sell stock" << std::endl;
          std::cout << "\ta - add cash" << std::endl;
          std::cout << "\tr - restart" << std::end;
          std::cout << "\tu - undo" << std::endl;
          std::cout << "\tq - quit" << std::endl;
}

Stock createStock() {
          Stock stock;
          std::string name;
          int numShares;
          double monthlyRate
          double threeMonthRate;
          double yearlyRate;
          std::cout << "Name :";
          std::cin >> name;
          stock.setNumShares(name);

          std::cout << "";
}
