#include "SolarPositionCalculation.h"

int main() {
	SolarPositionCalculation spc(2020, 12, 15);
	Date date = spc.calcDateFromJD(938985.123);
	std::cout << date.getYear() << "\n" << spc.getYear() << "\n" << spc.getMonth() << "\n" << spc.getDay() << "\n";
	
	std::cout << "\n" << spc.calcDoyFromJD(938985.123);

	return 0;
}