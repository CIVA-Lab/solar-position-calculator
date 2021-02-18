#include <iostream>
#include <cmath>
#include "AzimuthElevation.h"
#define PI 3.141593

using namespace std;

class TimeLocation {
	private:
	
	public:
	TimeLocation();
	double calcSolNoon(double jd, double longitude, double timezone);
	double calcSunriseSetUTC(bool rise, double JD, double latitude, double longitude);
	// rise = 1 for sunrise, 0 for sunset
	double calcSunriseSet(bool rise, double JD, double latitude, double longitude, double timezone);
	double calcJDofNextPrevRiseSet(double next, bool rise, double JD, double latitude, double longitude, double tz);
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
	bool isNumber(string inputVal);
	double calcRefraction(double elev);
	double calcTimeInMinutes(int hours, int mins, int secs);
	AzimuthElevation* calcAzEl(double T, double localtime, double latitude, double longitude, double zone);
};