#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include <vector>

class Portfolio {
	public:
		//operators
		
		//constructors
		Portfolio() : numStocks{0}, stockValue{0.0}, cashValue{0.0}, numYears{0} { stockVector(); };
		Portfolio(double numStocks = 0, double stockValue = 0.0, double cashValue = 0.0, int numYears 0) :
			numStocks{numStocks}, stockValue{stockValue}, cashValue{cashValue},
			numYears{numYears} { stockVector(); };
		Portfolio(Portfolio& portfolio) :
			numStocks{portfolio.getNumStocks()}, stockValue{portfolio.getStockValue()}, cashValue{portfolio.getCashValue()},
				stockVector();
				for(int i = 0; < portfolio.stockVector.size(); i++) {
					stockVector.push_back(portfolio.stockVector[i]);
				}
				numStocks = stockVector.size();
				kljakljfdlaldskaja
			};

		//getters and setters	
		int getNumStocks();
		double getValue();
		double getStockValue();
		double getCashValue();
		void setCashValue(double);
		
	private:
		Vector <Stock> stockVector;
		int numStocks;
		double value = stockValue + cashValue;
		double stockValue;
		double cashValue;
		int numYears;
}

//defintions
//operators

//constructors

//getters and setters

#endif
