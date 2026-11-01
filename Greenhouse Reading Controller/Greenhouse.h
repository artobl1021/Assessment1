// Header file (Greenhouse.h), contains definition of the library that we are going to use in main.cpp.
// Furthermore, it contains function declarations with parameters, so we can call it in main and 
// implement it in helper file Greenhouse.cpp.

#ifndef GREENHOUSE_H
#define GREENHOUSE_H

bool isReadingValid(double temperature, double humidity);
bool ventilationNeeded(double temperature);
bool ventilationNeeded(double temperature, double humidity);

void updateStatistics(double temperature,
					  int& validCount, 
					  double& temperatureTotal, 
					  double& highestTemperature);
#endif 