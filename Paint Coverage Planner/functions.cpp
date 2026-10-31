// This function only needs to read int width and int height to calculate area. 
// The variables do not need to change and function returns one result. 
// That's why we pass the arguments by value.
int calculateWallArea(int width, int height) {
	// Calculate wall area
	int wallArea = width * height; 
	// Return function result
	return wallArea;
}

// This function also reads only two numbers and returns one result. 
// We pass the arguments by value. The only difference is if statement and few local variables. 
int calculateCans(int totalArea, int coveragePerCan) {
	int cansRequired;
	// Calculate amount of cans without remainder.
	int cansRoughly = totalArea / coveragePerCan;
	// Calculate remainder of the division
	int remainder = totalArea % coveragePerCan;
	// If we have remainder we add one more can to the required cans number
	// and return cansRoughly.
	if (remainder > 0) {
		cansRequired = cansRoughly + 1;
		return cansRequired;
	}
	// If there is no remainder we return cans required from result of first calculation.
	return cansRoughly;
}

// In this function we are passing three arguments by value and three arguments by reference.
// The first three arguments (cans, pricePerCan, taxRate) are passed by value, because
// the function only needs to read them and they are the function's inputs.
// The other three arguments (subtotal, tax, total) are passed by reference, because
// this function has to give back three results and return can only give back one.
// The function is void, because the results are already passed back through reference.
void calculateCosts(int cans, 
				   double pricePerCan,
				   double taxRate,
				   double& subtotal,
				   double& tax,
				   double& total) {
	// Calculate subtotal.
	subtotal = cans * pricePerCan;
	// Calculate tax from subtotal.
	tax = subtotal * taxRate;
	// Calculate the total amount.
	total = subtotal + tax;
}