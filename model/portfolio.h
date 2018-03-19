#ifndef STOCKS_MODEL_CPP_PORTFOLIO_H
#define STOCKS_MODEL_CPP_PORTFOLIO_H

#include <map>

#include "stock.h"

namespace stocks {
class Portfolio {
  public:
    //constructors
    explicit Portfolio(double cash_value = 0.0) :
        cash_value{cash_value} {}
    Portfolio(const Portfolio& portfolio)
        : cash_value{portfolio.cash_value},
        stock_map{portfolio.stock_map} {}
    Portfolio(Portfolio && portfolio) :
        cash_value{std::move(portfolio.cash_value)},
        stock_map{std::move(portfolio.stock_map)} {
          portfolio.cash_value = 0.0;
          portfolio.stock_map.clear();
    }
    Portfolio& operator=(const Portfolio& portfolio) {
      cash_value = portfolio.cash_value;
      stock_map = portfolio.stock_map;
      return *this;
    }
    Portfolio& operator=(Portfolio&& portfolio) {
      cash_value = std::move(portfolio.cash_value);
      stock_map = std::move(portfolio.stock_map);
      portfolio.cash_value = 0.0;
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
    void remove_cash(const double& cash) {
      if (cash_value >= cash) {
        cash_value-=cash;
      } else {
        std::cerr << "*****INSUFFICIENT FUNDS IN PORTFOLIO*****" << std::endl;
      }
    };

    //add/remove stock
    void remove_stock(const Stock&);
    void add_stock(const Stock& stock) {
      if (stock_map.find(stock.get_name()) == stock_map.end()) {
        stock_map.insert(std::pair<std::string,
            Stock>(stock.get_name(), stock));
      } else {
        stock_map[stock.get_name()]+=stock.get_num_shares();
      }
    }

    //buy/sell stocks
    void sell_stock(const Stock&);
    void buy_stock(const Stock& stock) {
      if (cash_value >= stock.get_total_value()) {
        cash_value-= stock.get_total_value();
        add_stock(stock);
      } else {
        std::cerr << "*****INSUFFICIENT FUNDS IN PORTFOLIO*****" << std::endl;
      }
    }

    //print
    void print();

  private:
    //member data
    std::map<std::string, Stock> stock_map;
    double cash_value;
};

//remove stock
void Portfolio::remove_stock(const Stock& stock) {
  std::string key = stock.get_name();
  if (stock_map.find(key) != stock_map.end()) {
    if (stock_map[key].get_num_shares() > stock.get_num_shares()) {
      stock_map[key]-= stock.get_num_shares();
    } else if (stock_map[key].get_num_shares() == stock.get_num_shares()) {
      stock_map.erase(key);
    } else {
      std::cerr << "*****NOT ENOUGH SHARES*****" << std::endl;
    } 
  } else {
    std::cerr << "*****STOCK NOT FOUND*****" << std::endl;
  }
}

//sell stock
void Portfolio::sell_stock(const Stock& stock) {
  std::string key = stock.get_name();
  if (stock_map.find(stock.get_name()) != stock_map.end()) {
    if (stock_map[key].get_num_shares() >= stock.get_num_shares()) {
      cash_value+=stock.get_total_value();
      remove_stock(stock);
    } else {
      std::cerr << "*****NOT ENOUGH SHARES*****" << std::endl;
    }
  } else {
    std::cerr << "*****STOCK NOT FOUND*****" << std::endl;
  }
}

//print
void Portfolio::print() {
  std::cout << "\n---------------Portfolio---------------" << std::endl;
  std::cout << "Total Value: $" << get_total_value() << std::endl;
  std::cout << "Number of Holdings: " << stock_map.size() << std::endl;
  std::cout << "Stock Value: $" << get_stock_value() << std::endl;
  std::cout << "Cash Value: $" << get_cash_value() << std::endl << std::endl;
  for (auto i = stock_map.begin(); i != stock_map.end(); i++) {
    i->second.print();
  }
  std::cout << std::endl;
}
}

#endif
