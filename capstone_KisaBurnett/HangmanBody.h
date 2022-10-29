#ifndef HANGMANBODY_H
#define HANGMANBODY_H
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
using namespace std;

// Manages the console output of the gallows, body parts, and letter display,
// depending on the correct and incorrect guesses made by the player.
class HangmanBody
{
private:
	string head;
	string trunk;
	string armOne;
	string armTwo;
	string legOne;
	string legTwo;
	string galLine1;
	string galLine2;
	string galLine3;
	string galLine4H;
	string galLine5T;
	string galLine6TA;
	string galLine7L;
	string galLine8;
	string galLine9;
	string gallowsTop;
	string gallowsBottom;
public:
	HangmanBody() {
		galLine1 = "   +--+---------+\n";
		galLine2 = "   +--+---------+\n";
		galLine3 = "   |xx|      |\n";
		galLine4H = "   |xx|";
		galLine5T = "   |xx|";
		galLine6TA = "   |xx|";
		galLine7L = "   |xx|";
		galLine8 = "   |xx|\n";
		galLine9 = "   +--+----------\n";
		head = "      O";
		trunk = "      |";
		armOne = "     /|";
		armTwo = "     /|\\";
		legOne = "     /";
		legTwo = "     / \\";
		gallowsTop = galLine1 + galLine2 + galLine3;
		gallowsBottom = galLine8 + galLine9;
	}
	void gallows(int wrongAnswers);
	void wordDisplay(vector<char> guesses, string word, int wordSize, int wrongAnswers);
	void boxOutline(int iterations);
};
#endif