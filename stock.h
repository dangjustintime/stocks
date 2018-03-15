#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <iomanip>

class Stock {
	public:
		//operators
		friend std::ostream& operator<<(std::ostream&, const Stock&);
		friend bool operator==(const Stock&, const Stock&);
		friend bool operator!=(const Stock&, const Stock&);
		friend bool operator<(const Stock&, const Stock&);
		friend bool operator>(const Stock&, const Stock&);
		friend bool operator<=(const Stock&, const Stock&);
		friend bool operator>=(const Stock&, const Stock&);
		
		//constructors
		//default constructor
		explicit Stock(std::string name = "----",
                              int numShares = 0,
			double price = 0.0,
			double dailyRate = 0.0,
			double weeklyRate = 0.0,
			double monthlyRate = 0.0,
			double threeMonthRate = 0.0,
			double yearlyRate = 0.0,
			double generalRate = 0.0,
			double dividend = 0.0);
		//copy constructor
		Stock(const Stock&);
		//move constructor
		Stock(Stock&&);
		//assignment operator	
		Stock& operator=(const Stock&);
		//assignment operator (move version)
		Stock& operator=(Stock&&);

		//print
		void print() const;

		//getters and setters
		std::string getName() const;
		void setName(std::string);
                    int getNumShares() const;
                    void setNumShares(int);
		double getPrice() const;
		void setPrice(double);		
		double getDailyRate() const;
		void setDailyRate(double);
		double getWeeklyRate() const;
		void setWeeklyRate(double);
		double getMonthlyRate() const;
		void setMonthlyRate(double);
		double getThreeMonthRate() const;
		void setThreeMonthRate(double);
		double getYearlyRate() const;
		void setYearlyRate(double);
		double getGeneralRate() const;
		void setGeneralRate(double);
		double getDividend() const;
		void setDividend(double);

	private:
		std::string name;
                    int numShares;
		double price;
		double dailyRate;
		double weeklyRate;
		double monthlyRate;
		double threeMonthRate;
		double yearlyRate;
		double generalRate;
		double dividend;
};

//definitions
//operators

//constructors
//default constructor
Stock::Stock(std::string name,
          int numShares,
          double price,
          double dailyRate,
	double weeklyRate,
          double monthlyRate,
          double threeMonthRate,
	double yearlyRate,
          double wholeRate,
          double dividend) :
	          name{name},
                    numShares{numShares},
                    price{price},
                    dailyRate{dailyRate},
                    weeklyRate{weeklyRate},
	          monthlyRate{monthlyRate},
                    threeMonthRate{threeMonthRate},
                    yearlyRate{yearlyRate},
	          generalRate{wholeRate},
                    dividend{dividend} {};

//copy constructor
Stock::Stock(const Stock& stock) :
	name{stock.name},
          numShares{numShares},
          price{stock.price},
          dailyRate{stock.dailyRate},
	weeklyRate{stock.weeklyRate},
          monthlyRate{stock.monthlyRate},
          threeMonthRate{stock.threeMonthRate},
	yearlyRate{stock.yearlyRate},
          generalRate{stock.generalRate},
          dividend{stock.dividend} {};

//move constructor
Stock::Stock(Stock&& stock) :
	name{std::move(stock.name)},
          numShares{std::move(stock.numShares)},
          price{std::move(stock.price)},
          dailyRate{std::move(stock.dailyRate)},
	weeklyRate{std::move(stock.weeklyRate)},
          monthlyRate{std::move(stock.monthlyRate)},
          threeMonthRate{std::move(stock.threeMonthRate)},
	yearlyRate{std::move(stock.yearlyRate)},
          generalRate{std::move(stock.generalRate)},
          dividend{std::move(stock.dividend)} {
	          stock.name = "----";
                    stock.numShares = 0;
	          stock.price = 0.0;
	          stock.dailyRate = 0.0;
	          stock.weeklyRate = 0.0;
	          stock.monthlyRate = 0.0;
	          stock.threeMonthRate = 0.0;
	          stock.yearlyRate = 0.0;
	          stock.generalRate = 0.0;
	          stock.dividend = 0.0;
          };

//assignment operator
Stock& Stock::operator=(const Stock& stock) {
	name = stock.name;
          numShares = stock.numShares;
	price = stock.price;
	dailyRate = stock.dailyRate;
	weeklyRate = stock.weeklyRate;
	monthlyRate = stock.monthlyRate;
	threeMonthRate = stock.threeMonthRate;
	yearlyRate = stock.yearlyRate;
	generalRate = stock.generalRate;
	return *this;
};

//assignment operator (move version)
Stock& Stock::operator=(Stock&& stock){
	name = std::move(stock.name);
          numShares = std::move(stock.numShares);
	price = std::move(stock.price);
	dailyRate = std::move(stock.dailyRate);
	weeklyRate = std::move(stock.weeklyRate);
	monthlyRate = std::move(stock.monthlyRate);
	threeMonthRate = std::move(stock.threeMonthRate);
	yearlyRate = std::move(stock.yearlyRate);
	generalRate = std::move(stock.generalRate);
	stock.name = "----";
          stock.numShares = 0;
	stock.price = 0.0;
	stock.dailyRate = 0.0;
	stock.weeklyRate = 0.0;
	stock.monthlyRate = 0.0;
	stock.threeMonthRate = 0.0;
	stock.yearlyRate = 0.0;
	stock.generalRate = 0.0;
	stock.dividend = 0.0;
	return *this;
};

//print
void Stock::print() const {
	std::cout << "----------" << name << "----------" << std::endl;
          std::cout << "Number of shares: " << numShares << std::endl;
          std::cout << std::fixed;
	std::cout << "Price: $" << std::setprecision(2) << price << std::endl;
	std::cout << "Daily Rate: " << std::setprecision(2) << dailyRate << "%" << std::endl;
	std::cout << "Weekly Rate: " << std::setprecision(2) << weeklyRate << "%" << std::endl;
	std::cout << "Monthly Rate: " << std::setprecision(2) << monthlyRate << "%" << std::endl;
	std::cout << "Three Month Rate: " << std::setprecision(2) << threeMonthRate << "%" << std::endl;
	std::cout << "Yearly Rate: " << std::setprecision(2) << yearlyRate << "%" << std::endl;
	std::cout << "General Rate: " << std::setprecision(2) << generalRate << "%" << std::endl;
	std::cout << "Dividend: " << std::setprecision(2) << dividend << "%" << std::endl << std::endl;	
}

//getters and setters
std::string Stock::getName() const {  return name; };
void Stock::setName(std::string name) { this->name = name; };
int Stock::getNumShares() const { return numShares; };
void Stock::setNumShares(int numShares) { this->numShares = numShares; };
double Stock::getPrice() const { return price; };
void Stock::setPrice(double price) { this->price = price; };		
double Stock::getDailyRate() const { return dailyRate; };
void Stock::setDailyRate(double dailyRate) { this->dailyRate = dailyRate; };
double Stock::getWeeklyRate() const { return weeklyRate; };
void Stock::setWeeklyRate(double weeklyRate) { this->weeklyRate = weeklyRate; };
double Stock::getMonthlyRate() const { return monthlyRate; };
void Stock::setMonthlyRate(double monthlyRate) { this->monthlyRate = monthlyRate; };
double Stock::getThreeMonthRate() const { return threeMonthRate; };
void Stock::setThreeMonthRate(double threeMonthRate) { this->threeMonthRate = threeMonthRate; };
double Stock::getYearlyRate() const { return yearlyRate; };
void Stock::setYearlyRate(double yearlyRate) { this->yearlyRate = yearlyRate; };
double Stock::getGeneralRate() const { return generalRate; };
void Stock::setGeneralRate(double generalRate) { this->generalRate = generalRate; };
double Stock::getDividend() const { return dividend; };
void Stock::setDividend(double dividend) { this->dividend = dividend; };

#endif
