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
		Stock(); 
		//constructor with parameters
		Stock(std::string name = "----",
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

		//getters and setters
		std::string getName() const;
		void setName(std::string);
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

	private:
		std::string name;
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
std::ostream& operator<<(std::ostream& os, const Stock& stock) {
	std::fixed;
	os << "Name: " << stock.name << std::endl;
	os << "Price: " << std::setprecision(2) << stock.price << std::endl;
	os << "Daily Rate: " << std::setprecision(2) << stock.dailyRate << std::endl;
	os << "Weekly Rate: " << std::setprecision(2) << stock.weeklyRate << std::endl;
	os << "Monthly Rate: " << std::setprecision(2) << stock.monthlyRate << std::endl;
	os << "Three Month Rate: " << std::setprecision(2) << stock.threeMonthRate << std::endl;
	os << "Yearly Rate: " << std::setprecision(2) << stock.yearlyRate << std::endl;
	os << "General Rate: " << std::setprecision(2) << stock.generalRate << std::endl;
	os << "Dividend: " << std::setprecision(2) << stock.dividend << std::endl;
	return os;
};

//constructors
//default constructor
Stock::Stock() : name{"----"}, price{0.0}, dailyRate{0.0},
	weeklyRate{0.0}, monthlyRate{0.0}, threeMonthRate{0.0},
	yearlyRate{0.0}, generalRate{0.0},dividend{0.0} {};

//constructor with parameters
Stock::Stock(std::string name, double price, double dailyRate,
	double weeklyRate, double monthlyRate, double threeMonthRate,
	double yearlyRate, double wholeRate, double dividend) :
	name{name}, price{price}, dailyRate{dailyRate}, weeklyRate{weeklyRate},
	monthlyRate{monthlyRate}, threeMonthRate{threeMonthRate}, yearlyRate{yearlyRate},
	generalRate{wholeRate}, dividend{dividend} {};

//copy constructor
Stock::Stock(const Stock& stock) :
	name{stock.name}, price{stock.price}, dailyRate{stock.dailyRate},
	weeklyRate{stock.weeklyRate}, monthlyRate{stock.monthlyRate}, threeMonthRate{stock.threeMonthRate},
	yearlyRate{stock.yearlyRate}, generalRate{stock.generalRate}, dividend{stock.dividend} {};

//move constructor
Stock::Stock(Stock&& stock) :
	name{std::move(stock.name)}, price{std::move(stock.price)}, dailyRate{std::move(stock.dailyRate)},
	weeklyRate{std::move(stock.weeklyRate)}, monthlyRate{std::move(stock.monthlyRate)}, threeMonthRate{std::move(stock.threeMonthRate)},
	yearlyRate{std::move(stock.yearlyRate)}, generalRate{std::move(stock.generalRate)}, dividend{std::move(stock.dividend)} {};

//assignment operator
Stock& Stock::operator=(const Stock& stock) {
	name = stock.name;
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
	price = std::move(stock.price);
	dailyRate = std::move(stock.dailyRate);
	weeklyRate = std::move(stock.weeklyRate);
	monthlyRate = std::move(stock.monthlyRate);
	threeMonthRate = std::move(stock.threeMonthRate);
	yearlyRate = std::move(stock.yearlyRate);
	generalRate = std::move(stock.generalRate);
	return *this;
};

//getters and setters
std::string Stock::getName() const { return name; };
void Stock::setName(std::string) { this->name = name; };
double Stock::getPrice() const { return price; };
void Stock::setPrice(double) { this->price = price; };		
double Stock::getDailyRate() const {return dailyRate; };
void Stock::setDailyRate(double) { this->price = price; };
double Stock::getWeeklyRate() const { return weeklyRate; };
void Stock::setWeeklyRate(double) { this->weeklyRate = weeklyRate; };
double Stock::getMonthlyRate() const { return monthlyRate; };
void Stock::setMonthlyRate(double) { this->monthlyRate = monthlyRate; };
double Stock::getThreeMonthRate() const { return threeMonthRate; };
void Stock::setThreeMonthRate(double) { this->threeMonthRate; };
double Stock::getYearlyRate() const { return yearlyRate; };
void Stock::setYearlyRate(double) { this->yearlyRate; };
double Stock::getGeneralRate() const { return generalRate; };
void Stock::setGeneralRate(double) { this->generalRate = generalRate; };

#endif
