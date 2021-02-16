#include <iostream>
#include <math.h>
#include "Date.h"
#include "JulianDate.h"

class SolarPositionCalculation {
	private:
		int year;
		int month;
		int day;
	public:
		SolarPositionCalculation(int year, int month, int day);
		double calcTimeJulianCent(double jd);
		double calcJDFromJulianCent(double t);
		bool isLeapYear(int year);
		Date calcDateFromJD(double jd);
		
		double calcDoyFromJD(double jd);
		
		int getYear();
		int getMonth();
		int getDay();
};