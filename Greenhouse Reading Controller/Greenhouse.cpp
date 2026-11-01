// Greenhouse.cpp file contains functions implementation. When main.cpp calls the function,
// the code that runs is defined in this file.


// This function is used to validate user's input. If condtidions are met, it returns true.
bool isReadingValid(double temperature, double humidity) {
	
	if (temperature <= 60 && temperature >= -10 && humidity >= 0 && humidity <= 100) {
		return true;
	}
	return false;
}
// This function is used to establish if user needs a ventilation. It takes one argument: temperature.
// If conditions are met it returns true.
bool ventilationNeeded(double temperature) {
	if (temperature > 28) {
		return true;
	}
	return false;
}
// This overloaded function takes two arguments. It also checks if humidity is valid. 
bool ventilationNeeded(double temperature, double humidity) {
	if (temperature > 28 || humidity > 75) {
		return true;
	}
	return false;
}

// This function takes four arguments to calculate sum of temperature inputs needed to calculate average later. It also
// updates current highest temperature by using if statement.
void updateStatistics(double temperature,
					  int& validCount,
					  double& temperatureTotal,
					  double& highestTemperature) {
	
	temperatureTotal = temperatureTotal + temperature;
	if (temperature > highestTemperature) {
		highestTemperature = temperature;
	}
}