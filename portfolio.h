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

//add cash
void Portfolio::addCash(const double& cash) { cashValue+=cash; };

//remove cash
void Portfolio::removeCash(const double& cash) { cashValue-=cash;  };

//add stock (copy version)
void Portfolio::addStock(const Stock& stock) {
          stockMap.insert(std::pair<std::string, Stock>(stock.getName(), stock));
          numStocks++;
          stockValue+=stock.getPrice();
}
//add stock (move version)
void Portfolio::addStock(Stock&& stock) {
          stockMap.insert(std::pair<std::string, Stock>(stock.getName(), std::move(stock)));
          numStocks++;
          stockValue+=stock.getPrice();
	stock.setName("----");
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
        numStocks--;
        stockValue-= stockMap[stock.getName()].getPrice();
        stockMap.erase(stock.getName());
}

//buy stock
void Portfolio::buyStock(const Stock& stock) {
          if(cashValue >= stock.getPrice()) {
                    cashValue-= stock.getPrice();
                    if(stockMap.find(stock.getName()) != stockMap.end()) {
                              addStock(stock);
                    } else {
                              removeStock(stock);
                              addStock(stock);
                    }
          } else {
                    std::cout << "*****INSUFFICIENT FUNDS IN PORTFOLIO*****" << std::endl;
          }
}

//sell stock
void Portfolio::sellStock(const Stock& stock) {
          cashValue+= stockMap[stock.getName()].getPrice();
          removeStock(stock);
}

#endif
