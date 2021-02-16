#include "Date.h"

Date::Date(int year, int month, int day) {
	this->year = year;
	this->day = day;
	this->month = month;
}

int Date::getYear(){
	return year;
}

int Date::getMonth(){
	return month;
}			

int Date::getDay() {
	return day;
}

void Date::setYear(int y){
	this->year = y;
}

void Date::setMonth(int m){
	this->month = m;
}			

void Date::setDay(int d) {
	this->day = d;
}