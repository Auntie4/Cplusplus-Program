#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// function for the clocks' borders
void printClockBorder() {
	for (int i = 0; i < 16; ++i) {  // loop that prints space padding
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) {   // loop that prints *'s for the 12 - hour clock border	
		cout << "*";
	}
	for (int i = 0; i < 5; ++i) {  // loop that prints space padding between the clocks
		cout << " ";
	}
	for (int i = 0; i < 27; ++i) {   // loop that prints *'s for the 24 - hour clock border
		cout << "*";
	}
	cout << endl;
}
// outputs both clocks and converts the 24-hour clock to a 12-hour AM / PM clock
void printClocks(int hours, int minutes, int seconds) {
	// Necessary attributes used for the 12-hour conversion to make it successful
	int hourConv; // Hour conversion
	int minConv;  // Minute conversion
	int secConv;  // Second conversion
	string amPm = "AM"; // AM or PM
	// Covert 24-Hour to 12-Hour AM/PM clock
	if (hours == 0) {
		hourConv = 12;
	}
	else if (hours == 12) {
		hourConv = hours;
		amPm = "PM";
	}
	else if (hours > 12) {
		hourConv = hours - 12;
		amPm = "PM";
	}
	else {
		hourConv = hours;
	}
	// titles for the clocks
	cout << "\t\t*\t" << "12-Hour Clock";
	cout << "\t *";
	cout << "\t*" << "\t24-Hour Clock";
	cout << "\t *" << endl;

	// 12-hour clock
	cout << "\t\t* \t ";
	cout << setw(2) << setfill('0') << hourConv << ":";// The formatted 12-hour clock
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << " " << amPm;
	cout << "\t *";
	// 24-hour clock
	cout << "\t*" << "\t  ";
	cout << setw(2) << setfill('0') << hours << ":"; // The formatted 24-hour clock
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << "\t *" << endl;
}
// Function that takes in the initial time from the user imput
void inputInitialTime(int& setHour, int& setMinute, int& setSecond) {
	string inputString; // initial user input
	string tempString;  // user time input validation
	bool validTime = false;  // Valid time toggle used for the while statement
	int firstColonPosition; // the lst colon in inputString
	int secondColonPosition; // the 2nd colon in inputString

	while (!validTime) {
		cout << "Enter time as HH:MM:SS in 24-hour format: "; // Asks the user to input their initial time input
		getline(cin, inputString); // Assign user input
		firstColonPosition = inputString.find(':'); // Finds 1st colon	
		secondColonPosition = inputString.find(':', firstColonPosition + 1); // Finds 2nd colon
		// Using try to convert each clock section only if they were integers, otherwise ignoring them
		try {
			setHour = stoi(inputString.substr(0, firstColonPosition));
			// Takes in the first section and converts it to an integer
			setMinute = stoi(inputString.substr(firstColonPosition + 1,
				secondColonPosition)); // same as setHour
			setSecond = stoi(inputString.substr(secondColonPosition + 1,
				inputString.size() - 1)); // same as setHour
		}
		catch (const std::exception&) {
			// Not doing something with the exception in this program
		}
		if (inputString.size() != 8) {  // Check user entered the proper character length
			cout << "Time is invalid" << endl;
			!validTime;
		}
		else if (setHour < 0 || setHour > 23) { // Checking to make sure setHour is between 0 and 23
			cout << "Time is invalid" << endl;
			!validTime;
		}
		else if (setMinute < 0 || setMinute > 59) { // Checking to make sure setMinute is between 0 and 59
			cout << "Time is invalid" << endl;
			!validTime;
		}
		else if (setSecond < 0 || setSecond > 59) { // Checking to make sure setSecond is between 0 and 59
			cout << "Seconds are invalid" << endl;
			!validTime;
		}
		else {
			validTime = true; // Time is valid
		}
	}
}
// Main menu options 
void printMainMenu() {
	cout << endl;
	cout << " *********************************" << endl;
	cout << "* 1-Add One Hour\t\t*" << endl;
	cout << "* 2-Add One Minute\t\t*" << endl;
	cout << "* 3-Add One Second\t\t*" << endl;
	cout << "* 4-Exit\t\t\t*" << endl;
	cout << " *********************************" << endl;
	cout << endl;
}
// Function that takes in and validates user inputs
void processUserInput(int& userChoice, int& setHour, int& setMinute, int& setSecond) {
	cout << "Select option (1-4): "; // Ask user for option number
	// Verify user input is not other than an integer
	if (!(cin >> userChoice)) { // This statement ensures user only enters integers
		cin.clear();
		cin.ignore(numeric_limits<streamsize> ::max(), '\n'); // This ensures non-numerical values are ignored
		userChoice = 0;
	}
	// Utilizes the switch statement based on user's imt
	switch (userChoice) {
	case 1:
		cout << "1 hour added" << endl;
		if (setHour < 23) { // Increments 1 hour until the houur reaches 24
			++setHour;
		}
		else {
			setHour = 00; // Resets the hour to 00 once it reaches 24
		}
		break;
	case 2:
		cout << "1 minute added" << endl;
		if (setMinute < 59) { // Increments 1 minute until the minute reaches 59
			++setMinute;
		}
		else {
			setMinute = 00; // Resets the minutes to 00 once it reaches 59
		}
		break;
	case 3:
		if (setSecond < 59) { // Increments 1 second until the second reaches 59
			++setSecond;
		}
		else {
			setSecond = 00; // Resets the seconds to 00 once it reaches 59
		}
		break;
	case 4:
		cout << "Goodbye!" << endl;
		break;
	default:
		cout << "Invalid choice. Enter a number between 1-4 ... " << endl;
		cin.clear();
		break;
		}
	}
	int main() {
		// Declares the global properties
		int userChoice = 0;// user choice
		int setHour = 0;// initializes the clocks to midnight
		int setMinute = 0;
		int setSecond = 0;
		// Asks the user to enter the initial time
		inputInitialTime(setHour, setMinute, setSecond);
		// Enter program's while loop
		while (userChoice != 4) {
			// The Call clock functions
			printClockBorder(); // Clocks borders on the top
			printClocks(setHour, setMinute, setSecond); // Prints both clocks(the 24 and 12 hour)
			printClockBorder();// Clocks borders on the bottom
			printMainMenu(); // Prints main menu 
			processUserInput(userChoice, setHour, setMinute, setSecond);// Takes integer and modifies the clock based on command that was given
		}
		return 0;
	}