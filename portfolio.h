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

		//getters and setters	
		int getNumStocks();
		double getValue();
		double getStockValue();
		double getCashValue();
		void setCashValue(double);

                    void addStock();
                    void removeStock();
	private:
                    std::map<std::string, Stock> stockMap;
		int numStocks;
		double totalValue = stockValue + cashValue;
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
//getters and setters

#endif
