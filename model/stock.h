#ifndef STOCKS_MODEL_CPP_STOCK_H
#define STOCKS_MODEL_CPP_STOCK_H

#include <iomanip>
#include <iostream>
#include <string>

namespace stocks {
class Stock {
  public:
    // operators
    Stock& operator++() {
      num_shares++;
      return *this;
    }
    Stock& operator--() {
      num_shares--;
      return *this;
    };
    Stock operator++(int) {
      Stock oldStock(*this);
      num_shares++;
      return oldStock;
    }
    Stock operator--(int) {
      Stock oldStock(*this);
      if (this->num_shares > 1) {
        num_shares--;
      } else {
      	std::cerr << "*****NOT ENOUGH SHARES*****" << std::endl;
      }
      return oldStock;
    }
    Stock& operator+=(int num_shares) {
      this->num_shares+=num_shares;
      return *this; 
    }
    Stock& operator-=(int num_shares) {
      if (this->num_shares > num_shares) {
        this->num_shares-=num_shares;
      } else {
      	std::cerr << "*****NOT ENOUGH SHARES*****" << std::endl;
      }
      return *this; 
    }
    Stock& operator*=(int num_shares) {
      this->num_shares*=num_shares;
      return *this;
    }
    Stock& operator/=(int num_shares) {
      if (this->num_shares / num_shares > 1) {
        this->num_shares/=num_shares;
      } else {
      	std::cerr << "*****NOT ENOUGH SHARES*****" << std::endl;
      }
      return *this;
    }

    // constructor
    explicit Stock(std::string name = "----",
        int num_shares = 0,
        double price = 0.0,
        double daily_rate = 0.0,
        double weekly_rate = 0.0,
        double monthly_rate = 0.0,
        double three_month_rate = 0.0,
        double yearly_rate = 0.0,
        double general_rate = 0.0,
        double dividend = 0.0);
    Stock(const Stock&);
    Stock(Stock&&);
    Stock& operator=(const Stock&);
    Stock& operator=(Stock&&);

    // print
    void print() const;

    // getters and setters
    std::string get_name() const {
      return name;
    };
    void set_name(std::string name) {
      this->name = name;
    };
    int get_num_shares() const {
      return num_shares;
    };
    void set_num_shares(int num_shares) {
      this->num_shares = num_shares;
    };
    double get_price() const {
      return price;
    };
    void set_price(double price) {
      this->price = price;
    };		
    double get_daily_rate() const {
      return daily_rate;
    };
    void set_daily_rate(double daily_rate) {
      this->daily_rate = daily_rate;
    };
    double get_weekly_rate() const {
      return weekly_rate;
    };
    void set_weekly_rate(double weekly_rate) {
      this->weekly_rate = weekly_rate; 
    };
    double get_monthly_rate() const {
      return monthly_rate;
    };
    void set_monthly_rate(double monthly_rate) { 
      this->monthly_rate = monthly_rate; 
    };
    double get_three_month_rate() const {
      return three_month_rate;
    };
    void set_three_month_rate(double three_month_rate) { 
      this->three_month_rate = three_month_rate; 
    };
    double get_yearly_rate() const {
      return yearly_rate;
    };
    void set_yearly_rate(double yearly_rate) {
      this->yearly_rate = yearly_rate;
    };
    double get_general_rate() const {
      return general_rate;
    };
    void set_general_rate(double general_rate) {
      this->general_rate = general_rate;
    };
    double get_dividend() const {
      return dividend;
    };
    void set_dividend(double dividend) {
      this->dividend = dividend;
    };
    double get_total_value() const {
      return price * num_shares;
    };
  
  private:
    // member data
    std::string name;
    int num_shares;
    double price;
    double daily_rate;
    double weekly_rate;
    double monthly_rate;
    double three_month_rate;
    double yearly_rate;
    double general_rate;
    double dividend;
};

// default constructor
Stock::Stock(std::string name,
    int num_shares,
    double price,
    double daily_rate,
    double weekly_rate,
    double monthly_rate,
    double three_month_rate,
    double yearly_rate,
    double wholeRate,
    double dividend)
        : name{name},
        num_shares{num_shares},
        price{price},
        daily_rate{daily_rate},
        weekly_rate{weekly_rate},
        monthly_rate{monthly_rate},
        three_month_rate{three_month_rate},
        yearly_rate{yearly_rate},
        general_rate{wholeRate},
        dividend{dividend} {};

// copy constructor
Stock::Stock(const Stock& stock)
    : name{stock.name},
    num_shares{stock.num_shares},
    price{stock.price},
    daily_rate{stock.daily_rate},
    weekly_rate{stock.weekly_rate},
    monthly_rate{stock.monthly_rate},
    three_month_rate{stock.three_month_rate},
    yearly_rate{stock.yearly_rate},
    general_rate{stock.general_rate},
    dividend{stock.dividend} {};

// move constructor
Stock::Stock(Stock&& stock)
    : name{std::move(stock.name)},
    num_shares{std::move(stock.num_shares)},
    price{std::move(stock.price)},
    daily_rate{std::move(stock.daily_rate)},
    weekly_rate{std::move(stock.weekly_rate)},
    monthly_rate{std::move(stock.monthly_rate)},
    three_month_rate{std::move(stock.three_month_rate)},
    yearly_rate{std::move(stock.yearly_rate)},
    general_rate{std::move(stock.general_rate)},
    dividend{std::move(stock.dividend)} {
      stock.name = "----";
      stock.num_shares = 0;
      stock.price = 0.0;
      stock.daily_rate = 0.0;
      stock.weekly_rate = 0.0;
      stock.monthly_rate = 0.0;
      stock.three_month_rate = 0.0;
      stock.yearly_rate = 0.0;
      stock.general_rate = 0.0;
      stock.dividend = 0.0;
};

// assignment operator
Stock& Stock::operator=(const Stock& stock) {
  name = stock.name;
  num_shares = stock.num_shares;
  price = stock.price;
  daily_rate = stock.daily_rate;
  weekly_rate = stock.weekly_rate;
  monthly_rate = stock.monthly_rate;
  three_month_rate = stock.three_month_rate;
  yearly_rate = stock.yearly_rate;
  general_rate = stock.general_rate;
  dividend = stock.dividend;
  return *this;
};

// assignment operator (move version)
Stock& Stock::operator=(Stock&& stock){
  name = std::move(stock.name);
  num_shares = std::move(stock.num_shares);
  price = std::move(stock.price);
  daily_rate = std::move(stock.daily_rate);
  weekly_rate = std::move(stock.weekly_rate);
  monthly_rate = std::move(stock.monthly_rate);
  three_month_rate = std::move(stock.three_month_rate);
  yearly_rate = std::move(stock.yearly_rate);
  general_rate = std::move(stock.general_rate);
  dividend = std::move(stock.dividend);
  stock.name = "----";
  stock.num_shares = 0;
  stock.price = 0.0;
  stock.daily_rate = 0.0;
  stock.weekly_rate = 0.0;
  stock.monthly_rate = 0.0;
  stock.three_month_rate = 0.0;
  stock.yearly_rate = 0.0;
  stock.general_rate = 0.0;
  stock.dividend = 0.0;
  return *this;
};

// print
void Stock::print() const {
  std::cout << "----------" << get_name() << "----------" << std::endl;
  std::cout << "Total Value: $" << get_total_value() << std::endl;
  std::cout << "Number of shares: " << get_num_shares() << std::endl;
  std::cout << std::fixed;
  std::cout << "Price: $" << std::setprecision(2);
  std::cout << get_price() << std::endl;
  std::cout << "Daily Rate: " << std::setprecision(2);
  std::cout << get_daily_rate() << "%" << std::endl;
  std::cout << "Weekly Rate: " << std::setprecision(2);
  std::cout << get_weekly_rate() << "%" << std::endl;
  std::cout << "Monthly Rate: " << std::setprecision(2);
  std::cout << get_monthly_rate() << "%" << std::endl;
  std::cout << "Three Month Rate: " << std::setprecision(2);
  std::cout << get_three_month_rate() << "%" << std::endl;
  std::cout << "Yearly Rate: " << std::setprecision(2);
  std::cout << get_yearly_rate() << "%" << std::endl;
  std::cout << "General Rate: " << std::setprecision(2);
  std::cout << get_general_rate() << "%" << std::endl;
  std::cout << "Dividend: " << std::setprecision(2);
  std::cout << get_dividend() << "%" << std::endl;
  std::cout << std::endl;	
}
}

#endif
