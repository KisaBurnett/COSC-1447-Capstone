#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <limits>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Dictionary.h"
#include "HangmanBody.h"
#include "HangmanEngine.h"
#include "Player.h"
using namespace std;

// Prints out the gallows to the console. Adds body parts according to the 
// number of mistakes made by the player.
void HangmanBody::gallows(int wrongAnswers) {
	cout << gallowsTop;
	cout << galLine4H;
	if (wrongAnswers > 0) {
		cout << head;
	}
	cout << endl;
	cout << galLine5T;
	if (wrongAnswers > 1) {
		cout << trunk;
	}
	cout << endl;
	cout << galLine6TA;
	if (wrongAnswers == 2) {
		cout << trunk;
	}
	else if (wrongAnswers == 3) {
		cout << armOne;
	}
	else if (wrongAnswers > 3)
	{
		cout << armTwo;
	}
	cout << endl;
	cout << galLine7L;
	if (wrongAnswers == 5) {
		cout << legOne;
	}
	else if (wrongAnswers > 5) {
		cout << legTwo;
	}
	cout << endl;
	cout << gallowsBottom;
}

// Shows the current dictionary-chosen word, letter-by-letter, only revealing
// letters when they are correctly guessed by the player.
void HangmanBody::wordDisplay(vector<char> guesses, string word, int wordSize, int wrongAnswers) {
	bool showLetter = false;
	string printedLetter;

	boxOutline(wordSize);

	for (int letter = 0; letter < wordSize; letter++) {
		cout << "| ";
		for (int element = 0; element < guesses.size(); element++) {
			if (toupper(word[letter]) == toupper(guesses[element]) && !showLetter) {
				printedLetter = word[letter];
				cout << printedLetter;
				showLetter = true;
			}
		}
		if (!showLetter) {
			cout << "*";
		}
		else {
			showLetter = false;
		}
		cout << " ";
	}
	cout << "|" << endl;

	boxOutline(wordSize);
	if (wrongAnswers > 5) {
		cout << endl;
		cout << "+-----------------+" << endl;
		cout << "|    You lose!    |" << endl;
		cout << "+-----------------+" << endl;
	}
}

// Provides the outline for the letter boxes on the console.
void HangmanBody::boxOutline(int iterations) {
	for (int box = 0; box < iterations; box++) {
		cout << "+---";
	}

	cout << "+" << endl;
}