#include <iostream>

class Date {
	private:
		int year;
		int month;
		int day;
	public:
		Date(int year, int month, int day);
		
		int getYear();
		void setYear(int y);
		int getMonth();
		void setMonth(int m);
		int getDay();
		void setDay(int d);
};