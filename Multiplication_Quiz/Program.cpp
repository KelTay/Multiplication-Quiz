// This program asks the user random multiplication questions with operands
// in the range of 0 to 9.
//
// Author: Kelvin Tay
// Version: 1.0

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Define function prototypes
void multiplication();
void correctMessage();
void incorrectMessage();


// Function main
int main() {
	multiplication();
	system("pause");
}

// Asks the user random multiplication questions with operands in the 
// range 0 - 9. If the user is incorrect, displays incorrectMessage() and
// allows user to try again. If user is correct, displays correctMessage()
// and asks a new question. At any time, user can enter the sentinel value
// to exit the program.
void multiplication() {
	int operand1;
	int operand2;
	int product;
	int userAnswer;
	const int SENTINEL_NUMBER = -1;

	srand(time(0)); // Generate random seed based on time.

	cout << "Enter -1 to End." << endl;

	do {
		operand1 = rand() % 10;
		operand2 = rand() % 10;
		product = operand1 * operand2;

		cout << "How much is " << operand1 << " times " << operand2
			<< " (-1 to End)? ";

		cin >> userAnswer;

		while (userAnswer != product && userAnswer != SENTINEL_NUMBER) {
			incorrectMessage();
			cin >> userAnswer;
		}

		if (userAnswer == product) {
			correctMessage();
		}

	} while (userAnswer != SENTINEL_NUMBER);

	if (userAnswer == SENTINEL_NUMBER) {
		cout << "\nThat's all for now. Bye." << endl;
	}

}

// Displays a random message when user is correct.
void correctMessage() {
	int messageNumber = 1 + rand() % 4;
	string comment;

	switch (messageNumber) {
	    case 1:
			comment = "Very good!";
			break;
		case 2:
			comment = "Excellent!";
			break;
		case 3:
			comment = "Nice work!";
			break;
		case 4:
			comment = "Keep up the good work!";
			break;
		default:
			cerr << "Error in switch statement of correctMessage() function.";
			break;
	}
	cout << comment << "\n" << endl;
}

// Displays a random message when user is incorrect.
void incorrectMessage() {
	int messageNumber = 1 + rand() % 4;
	string comment;

	switch (messageNumber) {
	case 1:
		comment = "No. Please try again.";
		break;
	case 2:
		comment = "Wrong. Try once more.";
		break;
	case 3:
		comment = "Don't give up!";
		break;
	case 4:
		comment = "No. Keep trying.";
		break;
	default:
		cerr << "Error in switch statement of incorrectMessage() function.";
		break;
	}
	cout << comment << endl;
	cout << "? ";
}