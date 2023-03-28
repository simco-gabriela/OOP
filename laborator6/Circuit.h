#pragma once
#include <vector>
#include "Car.h"
#include "Weather.h"

class Circuit {
public:
	void SetLength(double length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks() const;
	void ShowWhoDidNotFinish() const;

private:
	double length;
	Weather weather;
	Car** cars;
	double* times;
	int num_cars;
	bool done = false;
};