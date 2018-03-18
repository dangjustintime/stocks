#ifndef STOCKS_CPP_PORTFOLIO_H
#define STOCKS_CPP_PORTFOLIO_H

#include <map>

#include "stock.h"

namespace stocks {
class Portfolio {
  public:
    //operators
    //constructors
    //default constructor	
    explicit Portfolio(double cash_value = 0.0, int num_years = 0) :
      cash_value{cash_value},
      num_years{num_years} {};
    //copy constructor
    Portfolio(const Portfolio& portfolio) :
      cash_value{portfolio.cash_value},
      num_years{portfolio.num_years},
      stock_map{portfolio.stock_map} {}
    //move constructor
    Portfolio(Portfolio && portfolio) :
      cash_value{std::move(portfolio.cash_value)},
      num_years{std::move(portfolio.num_years)},
      stock_map{std::move(portfolio.stock_map)} {
        portfolio.cash_value = 0.0;
        portfolio.num_years = 0;
        portfolio.stock_map.clear();
      }
    //assignment operator
    Portfolio& operator=(const Portfolio& portfolio) {
      cash_value = portfolio.cash_value;
      num_years = portfolio.num_years;
      stock_map = portfolio.stock_map;
      return *this;
    }
    //assignment operator (move version)
    Portfolio& operator=(Portfolio&& portfolio) {
      cash_value = std::move(portfolio.cash_value);
      num_years = std::move(portfolio.num_years);
      stock_map = std::move(portfolio.stock_map);
      portfolio.cash_value = 0.0;
      portfolio.num_years = 0;
      portfolio.stock_map.clear();  
      return *this;
    }

    //getters and setters
    double get_total_value() {
      return get_stock_value() + cash_value;
    }
    double get_stock_value() { 
      double stock_value = 0.0;
      for (auto i = stock_map.begin(); i != stock_map.end(); i++) {
        stock_value+=i->second.get_total_value();
      }
      return stock_value;
    }
    double get_cash_value() { return cash_value; };
    void set_cash_value(double cash_value) {
      this->cash_value = cash_value;
    }

    //add/remove cash
    void add_cash(const double& cash) { cash_value+=cash; };
    void remove_cash(const double& cash) { cash_value-=cash;  };

    //add stock (copy version)
    void add_stock(const Stock& stock) {
      if (stock_map.find(stock.getName()) == stock_map.end()) {
        stock_map.insert(std::pair<std::string, Stock>(stock.getName(), stock));
      } else {
        stock_map[stock.getName()]+=stock.getNumShares();
      }
    }
    //add stock (move version)
    void add_stock(Stock&& stock) {
      if (stock_map.find(stock.getName()) == stock_map.end()) {
        stock_map.insert(std::pair<std::string, Stock>(stock.getName(), std::move(stock)));
      } else {
        stock_map[stock.getName()]+=stock.getNumShares();
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
    void remove_stock(const Stock&);

    //buy/sell stocks
    void buy_stock(const Stock&);
    void sell_stock(const Stock&);

    //print
    void print();

  private:
    std::map<std::string, Stock> stock_map;
    double cash_value;
    int num_years;
};

//defintions
//add stock (move version)
void Portfolio::add_stock(Stock&& stock) {
if (stock_map.find(stock.getName()) == stock_map.end()) {
stock_map.insert(std::pair<std::string, Stock>(stock.getName(), std::move(stock)));
} else {
stock_map[stock.getName()]+=stock.getNumShares();
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
void Portfolio::remove_stock(const Stock& stock) {
if (stock_map.find(stock.getName()) != stock_map.end()) {
if (stock_map[stock.getName()].getNumShares() > stock.getNumShares()) {
stock_map[stock.getName()]-= stock.getNumShares();
} else if (stock_map[stock.getName()].getNumShares() == stock.getNumShares()) {
stock_map.erase(stock.getName());
} else {
std::cout << "*****NOT ENOUGH SHARES*****" << std::endl;
} 
} else {
std::cout << "*****STOCK NOT FOUND*****" << std::endl;
}
}

//buy stock
void Portfolio::buy_stock(const Stock& stock) {
if (cash_value >= stock.get_total_value()) {
cash_value-= stock.get_total_value();
add_stock(stock);
} else {
std::cout << "*****INSUFFICIENT FUNDS IN PORTFOLIO*****" << std::endl;
}
}

//sell stock
void Portfolio::sell_stock(const Stock& stock) {
if (stock_map.find(stock.getName()) != stock_map.end()) {
if (stock_map[stock.getName()].getNumShares() >= stock.getNumShares()) {
cash_value+=stock.get_total_value();
remove_stock(stock);
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
std::cout << "Total Value: $" << get_total_value() << std::endl;
std::cout << "Number of Holdings: " << stock_map.size() << "\t\tNumber of years: " << num_years << std::endl;
std::cout << "Stock Value: $" << get_stock_value() << "\t\tCash Value: $" << cash_value << std::endl << std::endl;
for (auto i = stock_map.begin(); i != stock_map.end(); i++) {
i->second.print();
}
std::cout << std::endl;
}

#endif
