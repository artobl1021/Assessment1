#ifndef PAINT_COVERAGE_H
#define PAINT_COVERAGE_H

int calculateWallArea(int width, int height);
int calculateCans(int totalArea, int coveragePerCan);
void calculateCosts(
	int cans, 
	double pricePerCan, 
	double taxRate,
	double& subtotal, 
	double& tax, 
	double& total);
#endif 
