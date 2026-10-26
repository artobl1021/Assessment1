#include <iostream>
using namespace std;

int main() {

	// Declare variables
	const int CORRECT_PIN = 4826;
	int inputPIN = 0;
	int inputsCounter = 0;
	int attempts = 0; 
	
	// While loop with counter set to 3 attempts (0, 1, 2)
	while (inputsCounter < 3){
		cout << "Enter your four digit PIN: ";
		cin >> inputPIN;

		// If statement checks if input is between 1000 and 9999.
		if (inputPIN < 1000 || inputPIN > 9999) {
			cout << "Invalid PIN. PIN must be between 1000 and 9999." << endl;
			continue;
		}
		// Else if statement checks if input is same as const CORRECT_PIN. If condition is fulfilled, loop is terminated.
		else if (inputPIN == CORRECT_PIN) {
			cout << "Your PIN is correct." << endl;
			break;
		}
		// If none of the above conditions are matched, we subtract current increased input counter from 3 attempts and display it to the user.
		else {
			inputsCounter++;
			attempts = 3 - inputsCounter;
			cout << "Incorrect PIN. " << attempts << " attempts remaining." << endl;
		}
	}
	// If statement checks if inputs counter is equal to 3. If it is, it will print the message informing that there are no attempts left.
	if (inputsCounter == 3) {
		cout << "Access locked." << endl;
	}
	
	return 0;
}


// Explanation 1 
// The while loop can end in two ways: 
// 1. If the user inputs correct PIN:
// else if (inputPIN == CORRECT_PIN) {
//		cout << "Your PIN is correct." << endl;
//		break;
// }
// which means that user entered correct PIN and loop breaks.
// 2. If user iputs incorrect PIN three times: 
//     else {
			//inputsCounter++;
			//attempts = 3 - inputsCounter;
			//cout << "Incorrect PIN. " << attempts << " attempts remaining." << endl;
//	   }
// By using "while (inputsCounter < 3)", loop condition is established. If inputsCounter increases from 0 to 1 and then to 2 
// and when inputCounter reaches 3, condition inputsCounter < 3 becomes false, so loop terminates.


// Explanation 2
// Counter has to be updated only when two conditions "if (inputPIN < 1000 || inputPIN > 9999)"
// and "else if (inputPIN == CORRECT_PIN)" are not fullfilled. If we would put counter inside 
// "if (inputPIN < 1000 || inputPIN > 9999)" statement, we would increase counter with every invalid input which is not
// what the program is intended to do. If we put counter increase inside "else if (inputPIN == CORRECT_PIN)" statement,
// we would increase attempts when the loop breaks, which does not make logical sense.
