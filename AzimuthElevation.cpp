#include "AzimuthElevation.h"

AzimuthElevation::AzimuthElevation() {

}

AzimuthElevation::AzimuthElevation(double azimuth, double elevation) {
	this->azimuth = azimuth;
	this->elevation = elevation;
}

void AzimuthElevation::setAzimuth(double az) {
	this->azimuth = az;
}

double AzimuthElevation::getAzimuth() {
	return this->azimuth;
}

void AzimuthElevation::setElevation(double el) {
	this->elevation = el;
}

double AzimuthElevation::getElevation() {
	return this->elevation;
}