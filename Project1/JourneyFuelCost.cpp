#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	// Declare variables
	double distance = 0.0;
	double consumption = 0.0;
	double pricePerLiter = 0.0;
	const double DIVISOR = 100.0;

	// ask user for input and reject if any input is zero or negative 
	cout << "Journey distance (in kilometers): ";
	cin >> distance;
	if (distance <= 0) {
		cout << "Input value must be greater than 0" << endl;
		return 1;
	}

	cout << "Vehicle fuel consumption per 100 kilometers (in liters): ";
	cin >> consumption;
	if (consumption <= 0) {
		cout << "Input value must be greater than 0" << endl; 
		return 1;
	}

	cout << "Fuel price (per liter): ";
	cin >> pricePerLiter;
	if (pricePerLiter <= 0) {
		cout << "Input value must be greater than 0" << endl;
		return 1;
	}

	// Calculate fuel used for journey
	double fuelUsed = 0.0;
	fuelUsed = distance * consumption / DIVISOR;

	// Calculate fuel cost
	double fuelCost = 0.0;
	fuelCost = fuelUsed * pricePerLiter;

	// Display fuel quantity and cost
	cout << fixed << setprecision(2) << "Fuel quantity: " << fuelUsed << "l" << endl;
	cout << fixed << setprecision(2) << "Fuel cost: " << fuelCost << "$" << endl;

	return 0;

}

//Explanation 1.
// Numeric variables should use floating point type, because liters and kilometers are usually calculated to two decimal places.
// Explanation 2.
// Compiling is translating source code into executable file and checking for mistakes in code. 
// Executing runs that file so program can ask for users input and calculate it.