#include <iostream>
using namespace std; 

int main() {
	// Declare variables
	int batteryPercentage = 0;
	double windSpeed = 0.0;
	int visibility = 0;
	char answer = ' ';
	bool isRestricted = false;
	
	// Ask user for input and validate 
	cout << "Enter current battery percentage: ";
	cin >> batteryPercentage;
	if (batteryPercentage < 0 || batteryPercentage > 100) {
		cout << "Error: Invalid input. Percentage must be between 0 and 100." << endl;
		return 1;
	}
	cout << "Enter wind speed (in km/h): ";
	cin >> windSpeed;
	
	if (windSpeed < 0) {
		cout << "Error: Invalid input. Wind speed cannot be negative." << endl;
		return 1;
	}
	cout << "Enter visibility (in meters): ";
	cin >> visibility;
	
	if (visibility < 0) {
		cout << "Error: Invalid input. Visibility cannot be negative." << endl;
		return 1;
	}
	
	// This part of code reads Y / N answer and stores it in bool. 
	cout << "Is location restricted? (Y / N): ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		isRestricted = true;
	}
	else if (answer == 'N' || answer == 'n') {
		isRestricted = false;
	}
	else {
		cout << "Invalid input, select Y or N" << endl;
		return 1;
	}
	
	// Validating clearance conditions and printing output. 
	bool clearance;
	clearance = batteryPercentage >= 30 && windSpeed <= 35 && visibility >= 500 && !isRestricted;
	
	if (batteryPercentage < 30) {
		cout << "Battery percentage too low." << endl;
	}
	if (windSpeed > 35) {
		cout << "Wind speed is too high." << endl;
	}
	if (visibility < 500) {
		cout << "Visibility too low." << endl;
	}
	if (answer == 'Y' || answer == 'y') {
		cout << "Area is restricted" << endl;
	}
	if (clearance) {
		cout << "Clearance granted." << endl;
	}
	
	return 0;
}

// Explanation 1

// Boolean expression states that the flight is cleared when all of these conditions are true: 
// clearance = batteryPercentage >= 30 && windSpeed <= 35 && visibility >= 500 && !isRestricted;
// - Battery percentage is at least 30 percent.
// - Wind speed is at most 35 kilometers per hour.
// - Visibility is at least 500 meters.
// - Location is not restricted (!isRestricted). ("!" means NOT. In this case it means if "isRestricted" is Not true.)
// In order to achieve these conditions I used relational operators like "<=", ">=", and logical operators "!", and "&&".
// "&&" in that case binds conditions together and helps us to assure that all conditions must be true.
// "!" in that case states that the condition isRestricted must be false in order to grant clearance. The rule 
// needs not restricted, so '!' flips that rule.
// I am also asking user if area is restricted.
// If user input would be 'y' or 'Y', isRestricted variable is set to true which means area is restricted.
// If user input would be 'n' or 'N', isRestricted value is set to false and it means that area is not restricted.


// Explanation 2

// I used 'if' statements, because it assure that each condition is checked independently. If I would use 'else if', if one 
// condition would be true, the rest would be skipped. Task needs every failure reported, because more that one rules
// can be not fulfilled at once.