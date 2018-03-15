#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include <map>

class Portfolio {
	public:
		//operators
		
		//constructors
	          //default constructor	
                    explicit Portfolio(double stockValue = 0.0,
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
                    void removeStock(const std::string&);

                    //buy/sell stocks
                    void buyStock(const Stock&);
                    void sellStock(const std::string&, int numShares = 1);

                    //print
                    void print();
	private:
                    std::map<std::string, Stock> stockMap;
		double stockValue;
		double cashValue;
		int numYears;
};

//defintions
//operators

//constructors
//default constructor
Portfolio::Portfolio(double stockValue,
          double cashValue,
          int numYears) :
                    stockValue{stockValue},
                    cashValue{cashValue},
	          numYears{numYears} {};
//copy constructor
Portfolio::Portfolio(const Portfolio& portfolio) :
        stockValue{portfolio.stockValue},
        cashValue{portfolio.cashValue},
        numYears{portfolio.numYears},
        stockMap{portfolio.stockMap} {}
//move constructor
Portfolio::Portfolio(Portfolio && portfolio) :
        stockValue{std::move(portfolio.stockValue)},
        cashValue{std::move(portfolio.cashValue)},
        numYears{std::move(portfolio.numYears)},
        stockMap{std::move(portfolio.stockMap)} {
                portfolio.stockValue = 0.0;
                portfolio.cashValue = 0.0;
                portfolio.numYears = 0;
                portfolio.stockMap.clear();
        }
//assignment operator
Portfolio& Portfolio::operator=(const Portfolio& portfolio) {
          stockValue = portfolio.stockValue;
          cashValue = portfolio.cashValue;
          numYears = portfolio.numYears;
          stockMap = portfolio.stockMap;
          return *this;
}
//assignment operator (move version)
Portfolio& Portfolio::operator=(Portfolio&& portfolio) {
          stockValue = std::move(portfolio.stockValue);
          cashValue = std::move(portfolio.cashValue);
          numYears = std::move(portfolio.numYears);
          stockMap = std::move(portfolio.stockMap);
          portfolio.stockValue = 0.0;
          portfolio.cashValue = 0.0;
          portfolio.numYears = 0;
          portfolio.stockMap.clear();  
          return *this;
}

//getters and setters
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
          stockValue+=stock.getTotalValue();
}
//add stock (move version)
void Portfolio::addStock(Stock&& stock) {
          stockMap.insert(std::pair<std::string, Stock>(stock.getName(), std::move(stock)));
          stockValue+=stock.getTotalValue();
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
void Portfolio::removeStock(const std::string& key) {
        stockValue-= stockMap[key].getTotalValue();
        stockMap.erase(key);
}

//buy stock
void Portfolio::buyStock(const Stock& stock) {
          if(cashValue >= stock.getTotalValue()) {
                    cashValue-= stock.getTotalValue();
                    if(stockMap.find(stock.getName()) != stockMap.end()) {
                              addStock(stock);
                    } else {
                              removeStock(stock.getName());
                              addStock(stock);  
                    }
          } else {
                    std::cout << "*****INSUFFICIENT FUNDS IN PORTFOLIO*****" << std::endl;
          }
}

//sell stock
void Portfolio::sellStock(const std::string& key, int numShares) {
          if(stockMap.find(key) != stockMap.end() && stockMap[key].getNumShares() >= numShares) {
                    cashValue+= stockMap[key].getPrice() * numShares;
                    if(numShares == 1) {
                              removeStock(key);
                    } else {
                              stockMap[key].setNumShares(stockMap[key].getNumShares() - numShares);
                    }
          } else if(stockMap.find(key) == stockMap.end()){
                    std::cout << "*****STOCK NOT FOUND*****" << std::endl;
          } else if(stockMap[key].getNumShares() < numShares) {
                    std::cout << "*****NOT ENOUGH SHARES*****" << std::endl;
          }
}

//print
void Portfolio::print() {
          std::cout << "\n---------------Portfolio---------------" << std::endl;
          std::cout << "Number of Holdings: " << stockMap.size() << "\t\tNumber of years: " << numYears << std::endl;
          std::cout << "Stock Value: " << stockValue << "\t\tCash Value: " << cashValue << std::endl << std::endl;
          for(auto i = stockMap.begin(); i != stockMap.end(); i++) {
                    i->second.print();
          }
          std::cout << std::endl;
}

#endif
