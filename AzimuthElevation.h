#include<iostream>

class AzimuthElevation {
	private:
		double azimuth;
		double elevation;
	public:
		AzimuthElevation(double azimuth, double elevation);
		AzimuthElevation();
		void setAzimuth(double az);
		double getAzimuth();
		void setElevation(double el);
		double getElevation();
};