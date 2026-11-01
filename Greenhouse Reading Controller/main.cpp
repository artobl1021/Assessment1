// Main.cpp controls the flow of the program. We include "Greenhouse.h" header file to ensure that we can call 
// functions from "Greenhouse.cpp" in main function. We do that to avoid any clutter and improve readability 
// of the code.

// The overloaded function selected for the per-reading recommendation is "ventilationNeeded(temperature, humidity)".
// It is selected because we are passing two arguments: temperature and humidity. Compiler checks these arguments and 
// matches with correct function. The other version is not used here because we always use two arguments.
#include <iostream>
#include <iomanip>
#include "Greenhouse.h"
using namespace std;

int main() {
	// Initialize variables
	int readingsCount = 0;
	double temperature = 0.0;
	double humidity = 0.0;
	int validCount = 0;
	double averageTemperature = 0.0;
	double highestTemperature = -11.0;
	double temperatureTotal = 0.0;
	int recommendationsYes = 0;
	int recommendationsNo = 0;

	
	// Ask user for number of readings needed.
	while (readingsCount < 1 || readingsCount > 10) {
		cout << "Enter the number of readings from 1 to 10" << endl;
		cin >> readingsCount;
		if (readingsCount < 1 || readingsCount > 10) {
			cout << "Invalid input: enter number from 1 to 10." << endl;
		}
	}

	// Initialize for loop with amount of iterations equal to user's input.
	for (int counter = 0; counter < readingsCount; counter++) {
		cout << "Please enter temperature from -10 to 60: " << endl;
		cin >> temperature;
		cout << "Please enter air humidity from 0% to 100%: " << endl;
		cin >> humidity;
		
		// While loop is necessary to check if reading is valid. User will be asked until correct input provided.
		while (!isReadingValid(temperature, humidity)) {
			cout << "Invalid reading: enter correct temperature -10 to 60: " << endl;
			cin >> temperature;
			cout << "Invalid reading: enter correct humidity 0% to 100%: " << endl;
			cin >> humidity;
		}
		// Display ventilation recommendations. Counters "recommendationsNo++" and "recommendationsYes++"
		// keep track of numbers of recommendations
		if (!ventilationNeeded(temperature, humidity)) {
			cout << "Temperature: " << temperature << "C. " << "Humidity: " << humidity << "%. "
				<< "Ventilation is not recommended." << endl;
			recommendationsNo++;
		}
		else {
			cout << "Temperature: " << temperature << "C. " << "Humidity: " << humidity << "%. "
				<< "Ventilation recommended." << endl;
			recommendationsYes++;
		}
		// Updating valid counts counter in order to calculate averageTemperature later.
		validCount++;
		updateStatistics(temperature, validCount, temperatureTotal, highestTemperature);
	}
	
	// Calculate averageTemperature.
	averageTemperature = temperatureTotal / validCount;

	// Display results.
	cout << fixed << setprecision(2) << "Highest temperature: " << highestTemperature << "C." << endl;
	cout << "Average temperature: " << averageTemperature << "C" << endl;
	cout << "Positive recommendations: " << recommendationsYes << "." << endl;
	cout << "Negative recommendations: " << recommendationsNo << "." << endl;
	
	return 0;
}