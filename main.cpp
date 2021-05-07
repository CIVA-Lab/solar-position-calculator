#include "SolarPositionCalculation.h"
#include "TimeLocation.h"
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])  {
	
	if(strcmp(argv[1],"--help") == 0) {
		cout << "Usage: ./solar-position-calculator -y [Year] -m [Month] -d [Day] -o [Longtitude] -a [Latitude] -u [Time zone offset] -t [Time]\n";
		cout << "Example Usage: ./solar-position-calculator -y 2021 -m 2 -d 15 -o -98.583 -a 39.833 -u -6:00 -t 11:37:52\n";
		return EXIT_SUCCESS;
	}

	TimeLocation *tl = new TimeLocation();

	int year, month, day, hours, minutes, seconds;
	int c;
	double longtitude, latitude, tz_hour_d, tz_min_d;
	string time_zone_offset, time, tz_hour, tz_min;
	string delimiter = ":";

	while((c = getopt(argc, argv, "y:m:d:o:a:u:t:")) != -1) {
		switch(c) {
			case 'y':
				year = atoi(optarg);
				break;
			case 'm':
				month = atoi(optarg);
				break;
			case 'd':
				day = atoi(optarg);
				break;
			case 'o':
				longtitude = atof(optarg);
				break;
			case 'a':
				latitude = atof(optarg);
				break;
			case 'u':
				time_zone_offset = optarg;
				tz_hour = time_zone_offset.substr(0, time_zone_offset.find(delimiter));
				tz_min = time_zone_offset.substr(time_zone_offset.find(delimiter)+1, time_zone_offset.length());

				tz_hour_d = atof(tz_hour.c_str());
				tz_min_d = atof(tz_min.c_str())/60.0;

				tz_hour_d = tz_hour_d + tz_min_d;
				break;
			case 't':
				time = optarg;

				hours = atoi(time.substr(0, time.find(delimiter)).c_str());
				time = time.substr(time.find(delimiter)+1, time.length());

				minutes = atoi(time.substr(0, time.find(delimiter)).c_str());
				time = time.substr(time.find(delimiter)+1, time.length());

				seconds = atoi(time.substr(0, time.length()).c_str());
				minutes = tl->calcTimeInMinutes(hours, minutes, seconds);
				break;
			default:
				cerr << "Wrong Usage" << endl;
				return EXIT_FAILURE;
		}
	}
	SolarPositionCalculation spc(year, month, day);
	double jday = spc.getJD();

	double total = jday + (minutes/1444.0) - (tz_hour_d/24.0);
	double T = spc.calcTimeJulianCent(total);
	AzimuthElevation azel = tl->calcAzEl(T, minutes, latitude, longtitude, tz_hour_d);

	cout << "Azimuth: "<< azel.getAzimuth() << ", Elevation: " << azel.getElevation() << endl;
	

	//delete &azel;
	delete tl;

	return EXIT_SUCCESS;
}
