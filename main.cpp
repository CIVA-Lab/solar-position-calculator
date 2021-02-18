#include "SolarPositionCalculation.h"
#include "TimeLocation.h"


int main(int argc, char *argv[]) {
	
	TimeLocation *tl = new TimeLocation();
	
	int year = atoi(argv[1]);
	int month = atoi(argv[2]);
	int day = atoi(argv[3]);
	double longtitude = atof(argv[4]);
	double latitude = atof(argv[5]);
	string time_zone_offset = argv[6];
	
	int hours = atoi(argv[7]);
	int minutes = atoi(argv[8]);
	int seconds = atoi(argv[9]);
	minutes = tl->calcTimeInMinutes(hours, minutes, seconds);
	
	//string time_zone_offset = argv[6];
	
	string delimiter = ":";
	string tz_hour = time_zone_offset.substr(0, time_zone_offset.find(delimiter));
	string tz_min = time_zone_offset.substr(time_zone_offset.find(delimiter)+1, time_zone_offset.length());
	cout << tz_hour << ":" << tz_min << endl;
	
	double tz_hour_d = atof(tz_hour.c_str());
	double tz_min_d = atof(tz_min.c_str())/60.0;
	
	tz_hour_d = tz_hour_d + tz_min_d;

	SolarPositionCalculation spc(year, month, day);
	double jday = spc.getJD();

	double total = jday + (minutes/1444.0) - (tz_hour_d/24.0);
	double T = spc.calcTimeJulianCent(total);
	AzimuthElevation azel = *tl->calcAzEl(T, minutes, latitude, longtitude, tz_hour_d);
	cout << azel.getAzimuth() << ", " << azel.getElevation() << endl;

	
	//Date date = spc.calcDateFromJD(938985.123);
	//std::cout << date.getYear() << "\n" << spc.getYear() << "\n" << spc.getMonth() << "\n" << spc.getDay() << "\n";
	
	//std::cout << "\n" << spc.getJD(2020,12,15);
	//std::cout << "\n" << spc.calcDoyFromJD(spc.getJD(2020,12,15));
	
	
	tl->calcSunriseSet(1, jday, latitude, longtitude, tz_hour_d);
	

	return 0;
}