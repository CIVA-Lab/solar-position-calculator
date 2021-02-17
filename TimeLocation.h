#include <iostream>
#include <cmath>
#include "AzimuthElevation.h"
//#include <string>

#define PI 3.141593

class TimeLocation {
	private:
	
	public:
	double calcSolNoon(double jd, double longitude, double timezone);
	double calcSunriseSetUTC(double rise, double JD, double latitude, double longitude);
	// rise = 1 for sunrise, 0 for sunset
	double calcSunriseSet(double rise, double JD, double latitude, double longitude, double timezone);
	double calcJDofNextPrevRiseSet(double next, double rise, double JD, double latitude, double longitude, double tz);
	double calcEquationOfTime(double t);
	double radToDeg(double angleRad);
	double degToRad(double angleDeg);
	double calcGeomMeanLongSun(double t);
	double calcGeomMeanAnomalySun(double t);
	double calcEccentricityEarthOrbit(double t);
	double calcSunEqOfCenter(double t);
	double calcSunTrueLong(double t);
	double calcSunTrueAnomaly(double t);
	double calcSunRadVector(double t);
	double calcSunApparentLong(double t);
	double calcMeanObliquityOfEcliptic(double t);
	double calcObliquityCorrection(double t);
	double calcSunRtAscension(double t);
	double calcSunDeclination(double t);
	double calcHourAngleSunrise(double lat, double solarDec);
	bool isNumber(std::string inputVal);
	double calcRefraction(double elev);
	AzimuthElevation* calcAzEl(double T, double localtime, double latitude, double longitude, double zone);
};