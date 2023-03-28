#include "RangeRover.h"
#include <string>


char* RangeRover::GetName() const {
	char* name = new char[20];
	strcpy_s(name, 20, "RangeRover");
	return name;
}
double RangeRover::GetFuelCapacity() const {
	return 85.0;
}

double RangeRover::GetFuelConsumption() const {
	return 11.0;
}

double RangeRover::GetAverageSpeed(Weather weather) const {
	switch (weather) {
	case Weather::Rain:
		return 90.0;
	case Weather::Sunny:
		return 95.0;
	case Weather::Snow:
		return 85.0;
	}
}