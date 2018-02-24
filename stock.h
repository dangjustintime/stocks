#ifdef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>

class Stock {
	public:
		//operators
		friend Stock& operator=(Stock&);
		friend std::ostream& operator<<(std::ostream&, const Stock&);
		
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
		Stock(Stock&);
		
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
//operators
Stock& operator=(Stock& stock) {
	Stock newStock(stock);
	return newStock;
};
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
Stock::Stock(std::string name, double price, double dailyRate,
	double weeklyRate, double monthlyRate, double threeMonthRate,
	double yearlyRate, double wholeRate, double dividend) :
	name{name}, price{price}, dailyRate{dailyRate}, weeklyRate{weeklyRate},
	monthlyRate{monthlyRate}, threeMonthRate{threeMonthRate}, yearlyRate{yearlyRate},
	generalRate{wholeRate}, dividend{dividend} {};
Stock::Stock(Stock& stock) :
	name{stock.name}, price{stock.price}, dailyRate{stock.dailyRate},
	weeklyRate{stock.weeklyRate}, monthylRate{stock.monthlyRate}, threeMonthRate{stock.threeMonthRate},
	yearlyRate{stock.yearlyRate}, generalRate{stok.generalRate}, dividend{stock.dividend}, {};


//getters and setters
std::string Stock::getName() { return name; };
void Stock::setName(std::string) { this->name = name; };
double Stock::getPrice() { return price; };
void Stock::setPrice(double) { this->price = price; };		
double Stock::getDailyRate() {return dailyRate; };
void Stock::setDailyRate(double) { this->price = price; };
double Stock::getWeeklyRate() { return weeklyRate; };
void Stock::setWeeklyRate(double) { this->weeklyRate = weeklyRate; };
double Stock::getMonthlyRate() { return monthlyRate; };
void Stock::setMonthlyRate(double) { this-monthlyRate = monthlyRate; };
double Stock::getThreeMonthRate() { return threeMonthRate; };
void Stock::setThreeMonthRate(double) { this->threeMonthRate; };
double Stock::getYearlyRate() { return yearlyRate; };
void Stock::setYearlyRate(double) { this->yearlyRate; };
double Stock::getGeneralRate() { return generalRate; };
void Stock::setGeneralRate(double) { this->generalRate = generalRate; };

#endif
