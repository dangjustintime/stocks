#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include <map>

class Portfolio {
	public:
		//operators
		
		//constructors
	          //default constructor	
                    explicit Portfolio(int numStocks = 0.0,
                                    double stockValue = 0.0,
                                    double cashValue = 0.0,
                                    int numYears = 0);
                    //copy constructor
                    Portfolio(const Portfolio&);
                    //move constructor
                    Portfolio(Portfolio&&);
                    //assignment operator
                    Portfolio& operator=(const Portfolio&);
                    //assignment operator (move version)
                    Portfolio& operator=(Portfolio&&);

		//getters and setters	
		int getNumStocks();
		double getTotalValue();
		double getStockValue();
		double getCashValue();
		void setCashValue(double);

                    void addStock(Stock);
                    void removeStock(std::string);
	private:
                    std::map<std::string, Stock> stockMap;
		int numStocks;
		double stockValue;
		double cashValue;
		int numYears;
};

//defintions
//operators

//constructors
//default constructor
Portfolio::Portfolio(int numStocks,
          double stockValue,
          double cashValue,
          int numYears) :
	          numStocks{numStocks},
                    stockValue{stockValue},
                    cashValue{cashValue},
	          numYears{numYears} {};
//copy constructor
Portfolio::Portfolio(const Portfolio& portfolio) :
        numStocks{portfolio.numStocks},
        stockValue{portfolio.stockValue},
        cashValue{portfolio.cashValue},
        numYears{portfolio.numYears},
        stockMap{portfolio.stockMap} {}
//move constructor
Portfolio::Portfolio(Portfolio && portfolio) :
        numStocks{std::move(portfolio.numStocks)},
        stockValue{std::move(portfolio.stockValue)},
        cashValue{std::move(portfolio.cashValue)},
        numYears{std::move(portfolio.numYears)},
        stockMap{std::move(portfolio.stockMap)} {
                portfolio.numStocks = 0;
                portfolio.stockValue = 0.0;
                portfolio.cashValue = 0.0;
                portfolio.numYears = 0;
                portfolio.stockMap.clear();
        }
//assignment operator
Portfolio& Portfolio::operator=(const Portfolio& portfolio) {
          numStocks = portfolio.numStocks;
          stockValue = portfolio.stockValue;
          cashValue = portfolio.cashValue;
          numYears = portfolio.numYears;
          stockMap = portfolio.stockMap;
          return *this;
}
//assignment operator (move version)
Portfolio& Portfolio::operator=(Portfolio&& portfolio) {
          numStocks = std::move(portfolio.numStocks);
          stockValue = std::move(portfolio.stockValue);
          cashValue = std::move(portfolio.cashValue);
          numYears = std::move(portfolio.numYears);
          stockMap = std::move(portfolio.stockMap);
          portfolio.numStocks = 0;
          portfolio.stockValue = 0.0;
          portfolio.cashValue = 0.0;
          portfolio.numYears = 0;
          portfolio.stockMap.clear();  
          return *this;
}

//getters and setters
int Portfolio::getNumStocks() { return numStocks; };
double Portfolio::getTotalValue() { return stockValue + cashValue; };
double Portfolio::getStockValue() { return stockValue; };
double Portfolio::getCashValue() { return cashValue; };
void Portfolio::setCashValue(double cashValue) { this->cashValue = cashValue; }

#endif
