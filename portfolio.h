#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include <map>

class Portfolio {
	public:
		//operators
		
		//constructors
	          //default constructor	
                    explicit Portfolio(double cashValue = 0.0, int numYears = 0);
                    //copy constructor
                    Portfolio(const Portfolio&);
                    //move constructor
                    Portfolio(Portfolio&&);
                    //assignment operator
                    Portfolio& operator=(const Portfolio&);
                    //assignment operator (move version)
                    Portfolio& operator=(Portfolio&&);

		//getters and setters	
		double getTotalValue();
		double getStockValue();
		double getCashValue();
		void setCashValue(double);

                    //add/remove cash
                    void addCash(const double&);
                    void removeCash(const double&);

                    //add/remove stocks
                    void addStock(const Stock&);
                    void addStock(Stock&&);
                    void removeStock(const Stock&);

                    //buy/sell stocks
                    void buyStock(const Stock&);
                    void sellStock(const Stock&);

                    //print
                    void print();
	private:
                    std::map<std::string, Stock> stockMap;
		double cashValue;
		int numYears;
};

//defintions
//operators

//constructors
//default constructor
Portfolio::Portfolio(double cashValue, int numYears) :
          cashValue{cashValue},
	numYears{numYears} {};
//copy constructor
Portfolio::Portfolio(const Portfolio& portfolio) :
        cashValue{portfolio.cashValue},
        numYears{portfolio.numYears},
        stockMap{portfolio.stockMap} {}
//move constructor
Portfolio::Portfolio(Portfolio && portfolio) :
        cashValue{std::move(portfolio.cashValue)},
        numYears{std::move(portfolio.numYears)},
        stockMap{std::move(portfolio.stockMap)} {
                portfolio.cashValue = 0.0;
                portfolio.numYears = 0;
                portfolio.stockMap.clear();
        }
//assignment operator
Portfolio& Portfolio::operator=(const Portfolio& portfolio) {
          cashValue = portfolio.cashValue;
          numYears = portfolio.numYears;
          stockMap = portfolio.stockMap;
          return *this;
}
//assignment operator (move version)
Portfolio& Portfolio::operator=(Portfolio&& portfolio) {
          cashValue = std::move(portfolio.cashValue);
          numYears = std::move(portfolio.numYears);
          stockMap = std::move(portfolio.stockMap);
          portfolio.cashValue = 0.0;
          portfolio.numYears = 0;
          portfolio.stockMap.clear();  
          return *this;
}

//getters and setters
double Portfolio::getTotalValue() { return getStockValue() + cashValue; };
double Portfolio::getStockValue() { 
          double stockValue = 0.0;
          for(auto i = stockMap.begin(); i != stockMap.end(); i++) {
                    stockValue+=i->second.getTotalValue();
          }
          return stockValue;
};
double Portfolio::getCashValue() { return cashValue; };
void Portfolio::setCashValue(double cashValue) { this->cashValue = cashValue; }

//add cash
void Portfolio::addCash(const double& cash) { cashValue+=cash; };

//remove cash
void Portfolio::removeCash(const double& cash) { cashValue-=cash;  };

//add stock (copy version)
void Portfolio::addStock(const Stock& stock) {
          if(stockMap.find(stock.getName()) == stockMap.end()) {
                    stockMap.insert(std::pair<std::string, Stock>(stock.getName(), stock));
          } else {
                    stockMap[stock.getName()]+=stock.getNumShares();
          }
}
//add stock (move version)
void Portfolio::addStock(Stock&& stock) {
          if(stockMap.find(stock.getName()) == stockMap.end()) {
                    stockMap.insert(std::pair<std::string, Stock>(stock.getName(), std::move(stock)));
          } else {
                    stockMap[stock.getName()]+=stock.getNumShares();
          }

          stock.setName("----");
          stock.setNumShares(0);
	stock.setPrice(0.0);
	stock.setDailyRate(0.0);
	stock.setWeeklyRate(0.0);
	stock.setMonthlyRate(0.0);
	stock.setThreeMonthRate(0.0);
	stock.setYearlyRate(0.0);
	stock.setGeneralRate(0.0);
	stock.setDividend(0.0);          
}

//remove stock
void Portfolio::removeStock(const Stock& stock) {
        if(stockMap.find(stock.getName()) != stockMap.end()) {
                if(stockMap[stock.getName()].getNumShares() > stock.getNumShares()) {
                        stockMap[stock.getName()]-= stock.getNumShares();
                } else if (stockMap[stock.getName()].getNumShares() == stock.getNumShares()) {
                        stockMap.erase(stock.getName());
                } else {
                        std::cout << "*****NOT ENOUGH SHARES*****" << std::endl;
                } 
        } else {
                        std::cout << "*****STOCK NOT FOUND*****" << std::endl;
        }
}

//buy stock
void Portfolio::buyStock(const Stock& stock) {
          if(cashValue >= stock.getTotalValue()) {
                    cashValue-= stock.getTotalValue();
                    addStock(stock);
          } else {
                    std::cout << "*****INSUFFICIENT FUNDS IN PORTFOLIO*****" << std::endl;
          }
}

//sell stock
void Portfolio::sellStock(const Stock& stock) {
        if(stockMap.find(stock.getName()) != stockMap.end()) {
                if(stockMap[stock.getName()].getNumShares() >= stock.getNumShares()) {
                        cashValue+=stock.getTotalValue();
                        removeStock(stock);
                } else {
                        std::cout << "*****NOT ENOUGH SHARES*****" << std::endl;
                }
        } else {
                std::cout << "*****STOCK NOT FOUND*****" << std::endl;
        }
}

//print
void Portfolio::print() {
          std::cout << "\n---------------Portfolio---------------" << std::endl;
          std::cout << "Number of Holdings: " << stockMap.size() << "\t\tNumber of years: " << numYears << std::endl;
          std::cout << "Stock Value: " << getStockValue() << "\t\tCash Value: " << cashValue << std::endl << std::endl;
          for(auto i = stockMap.begin(); i != stockMap.end(); i++) {
                    i->second.print();
          }
          std::cout << std::endl;
}

#endif
