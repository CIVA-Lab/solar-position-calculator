#include "SolarPositionCalculation.h"
//#include "JulianDate.h"
//#include "Date.h"

SolarPositionCalculation::SolarPositionCalculation() {

}

SolarPositionCalculation::SolarPositionCalculation(int year, int month, int day) {
	this->year = year;
	this->day = day;
	this->month = month;
}

double SolarPositionCalculation::calcTimeJulianCent(double jd) {
	double T = (jd - 2451545.0)/36525.0;
	return T;
}

double SolarPositionCalculation::calcJDFromJulianCent(double t) {
	double JD = t * 36525.0 + 2451545.0;
	return JD;
}

bool SolarPositionCalculation::isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

Date SolarPositionCalculation::calcDateFromJD(double jd) {
	double z = floor(jd + 0.5);
	double f = (jd + 0.5) - z;
	double A;
	if (z < 2299161) {
		A = z;
	} else {
		double alpha = floor((z - 1867216.25)/36524.25);
		A = z + 1 + alpha - floor(alpha/4);
	}
	double B = A + 1524;
	double C = floor((B - 122.1)/365.25);
	double D = floor(365.25 * C);
	double E = floor((B - D)/30.6001);
	this->day = B - D - floor(30.6001 * E) + f;
	this->month = (E < 14) ? E - 1 : E - 13;
	this->year = (this->month > 2) ? C - 4716 : C - 4715;
	std::cout << "\n" << this->year;
	Date date(this->year, this->month, this->day);

	return date;
}

double SolarPositionCalculation::calcDoyFromJD(double jd) {
	Date date = calcDateFromJD(jd);
	std::cout << "\n" << date.getYear();
	int k = (isLeapYear(date.getYear()) ? 1 : 2);
	double doy = floor((275 * date.getMonth())/9.0) - k * floor((date.getMonth() + 9)/12.0) + date.getDay() -30;

	return doy;
}

double SolarPositionCalculation::getJD() {
	if (month <= 2) {
		year -= 1;
		month += 12;
	}
	double A = floor(year/100);
	double B = 2 - A + floor(A/4);
	double JD = floor(365.25*(year + 4716)) + floor(30.6001*(month+1)) + day + B - 1524.5;
	return JD;
}


int SolarPositionCalculation::getYear(){
	return year;
}

int SolarPositionCalculation::getMonth(){
	return month;
}			

int SolarPositionCalculation::getDay() {
	return day;
}


