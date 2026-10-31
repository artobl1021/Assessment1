#include <iostream>
#include <iomanip>
#include "header.h"
using namespace std;

const int COVERAGE = 12;
const double PRICE_PER_CAN = 24.50;
const double TAX_RATE = 0.05;

int main() {
	
	// Initialize variables
	int wallCount = 0;
	int wallArea = 0;
	int totalArea = 0;
	int cans = 0;
	double subtotal = 0.0;
	double tax = 0.0;
	double total = 0.0;

	// Setting correct condition for while loop.
	while (wallCount < 1 || wallCount > 8) {
		cout << "Enter number of walls to paint: " << endl; // Ask user for input.
		cin >> wallCount;
		// If input is incorrect, we display error and we go back to the beggining of the loop
		if (wallCount < 1 || wallCount > 8) {
			cout << "Invalid input: Enter walls number from 1 to 8." << endl;
		}
	}

	// To ask user for each wall we need to use wallCount as a number of for loops inside.
	// After one iteration we increase counter +1 until it reaches condition.
	for (int counter = 0; counter < wallCount; counter++) {
		// Initialize values at zero, so while loop condition is fulfilled.
		int width = 0;
		int height = 0;
	// Ask user for width and height in each iteration of the loop.
		// While loop for input validation.
		while (width <= 0) {
			cout << "Enter the width of wall " << counter + 1 << " in whole meters :" << endl;
			cin >> width;
			if (width <= 0) {
				cout << "Invalid input: height must be a positive number." << endl;
			}
		}
		// While loop for input validation.
		while (height <= 0) {
			cout << "Enter the height of wall " << counter + 1 << " in whole meters :" << endl;
			cin >> height;
			if (height <= 0) {
				cout << "Invalid input: height must be a positive number." << endl;
			}
		}
		// Calling the function implemented in functions.cpp
		wallArea = calculateWallArea(width, height);
		// Adding each wall area tokeep track on total area.
		totalArea = totalArea + wallArea;
		}
		
	// Calculate cans necessary to paint the totalArea.
	cans = calculateCans(totalArea, COVERAGE);
	
	// Calculate subtotal, tax and total amount for cans.
	calculateCosts(cans, PRICE_PER_CAN, TAX_RATE, subtotal, tax, total);
	cout << "Total Area is: " << totalArea << " square meters." << endl;
	cout << "Number of cans needed: " << cans << " cans" << endl;
	cout << fixed << setprecision(2) << "Subtotal: " << subtotal << "$" << endl; 
	cout << "Tax: " << tax << "$" << endl;
	cout << "Total: " << total << "$" << endl;
	
	return 0;

}