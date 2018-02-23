#ifdef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>

class Stock {
	friend Stock& operator=(Stock& stock);
	
	public:
		//constructors
		Stock() : 
			name{"----"},
			price{0.0}, 
			dailyRate{0.0}
			weeklyRate{0.0}, 
			monthlyRate{0.0},
			threeMonthRate{0.0},
			yearlyRate{0.0},
			generalRate{0.0},
			dividend{0.0} {};
		Stock(std::string name = "----",
			double price = 0.0,
			double dailyRate = 0.0,
			double weeklyRate = 0.0,
			double monthlyRate = 0.0,
			double threeMonthRate = 0.0,
			double yearlyRate = 0.0,
			double generalRate = 0.0,
			double dividend = 0.0);
		
		//getters and setters
		std::string getName();
		void setName(std::string);
		double getPrice();
		void setPrice(double);		
		double getDailyRate();
		void setDailyRate(double);
		double getWeeklyRate();
		void setWeeklyRate(double);
		double getMonthlyRate();
		void setMonthlyRate(double);
		double getThreeMonthRate();
		void setThreeMonthRate(double);
		double getYearlyRate();
		void setYearlyRate(double);
		double getGeneralRate();
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
//constructors
Stock::Stock(std::string name, double price, double dailyRate,
	double weeklyRate, double monthlyRate, double threeMonthRate,
	double yearlyRate, double wholeRate, double dividend) :
	name{name}, price{price}, dailyRate{dailyRate}, monthlyRate{monthlyRate},
	threeMonthRate{threeMonthRate}, double yearlyRate{yearlyRate}, double generalRate{wholeRate},
	double dividend{dividend} {};

//getters and setters
std::string Stock::getName();
void Stock::setName(std::string);
double Stock::getPrice();
void Stock::setPrice(double);		
double Stock::getDailyRate();
void Stock::setDailyRate(double);
double Stock::getWeeklyRate();
void Stock::setWeeklyRate(double);
double Stock::getMonthlyRate();
void Stock::setMonthlyRate(double);
double Stock::getThreeMonthRate();
void Stock::setThreeMonthRate(double);
double Stock::getYearlyRate();
void Stock::setYearlyRate(double);
double Stock::getGeneralRate();
void Stock::setGeneralRate(double);

#endif
