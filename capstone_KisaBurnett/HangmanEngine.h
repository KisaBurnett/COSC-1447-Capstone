#ifndef HANGMANENGINE_H
#define HANGMANENGINE_H
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

// Manages the game sequence of Hangman, including validating and tracking
// input by the player and output from the console.
class HangmanEngine
{
private:
	bool playAgain;
	char guessedLetter;
	int gamesPlayed;
	int gamesLost;
	int mistakes;
	int wordLength;
	string currentWord;
	string playAgainInput;
	vector<char> lettersCorrect;
public:
	HangmanEngine() {
		playAgain = true;
		guessedLetter = '1';
		gamesPlayed = 0;
		gamesLost = 0;
		mistakes = 0;
		wordLength = 0;
		currentWord = "";
		playAgainInput = "";
	}
	void play();
	void startTutorial();
	void playerTurn(vector<char> correctGuesses);
	void checkLetter(char guess, string word, int wordSize, vector<char> guessList);
	bool playAgainCheck();
	void addGamePlayed();
	int getGamesPlayed();
};
#endif