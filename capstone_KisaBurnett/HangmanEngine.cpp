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

// Manages the Hangman game sequence.
void HangmanEngine::play() {
	Dictionary gameDictionary;
	Player playerInfo;
	HangmanBody hangman;

	startTutorial();

	do {
		mistakes = 0;
		addGamePlayed();
		gameDictionary.getWords();
		playerInfo.resetCorrectGuesses();
		lettersCorrect = playerInfo.guessCorrectList();
		currentWord = gameDictionary.pickWord();
		wordLength = currentWord.size();

		while ((mistakes < 7) && (lettersCorrect.size() < currentWord.size())) {
			hangman.gallows(mistakes);
			hangman.wordDisplay(lettersCorrect, currentWord, wordLength, mistakes);
			cout << endl;
			if (mistakes < 6 && (lettersCorrect.size() < currentWord.size())) {
				playerTurn(lettersCorrect);
			}
			else {
				break;
			}
		}

		if ((lettersCorrect.size() == currentWord.size())) {
			hangman.gallows(mistakes);
			hangman.wordDisplay(lettersCorrect, currentWord, wordLength, mistakes);
			cout << endl;
			cout<< "+----------------+" << endl;
			cout << "|    You win!    |" << endl;
			cout << "+----------------+" << endl;
			cout << endl;
			playerInfo.addWin();
		}

		playAgain = playAgainCheck();

	} while (playAgain);

	playerInfo.playerStats(getGamesPlayed());
}

// Prints out a welcome and tutorial for the player.
void HangmanEngine::startTutorial() {
	string goOn = "";
	cout << "Welcome to Hangman!\n\n";
	cout << "In this game, you must guess the hidden word in order to save a person from execution." << endl;
	cout << "You will be shown the number of spaces for the letters as a hint, and as you correctly" << endl;
	cout << "guess the hidden letters, they will be revealed to you, making it easier for you to " << endl;
	cout << "make your next guess. But beware! Six mistakes, and it's game over for you..." << endl;
	cout << "...and your friend, too!\n\n";
	cout << "Enter a letter from A to Z and press 'Enter' to make your guess.\n\n";

	cout << "Enter any key to get started: ";
	cin >> goOn;
	cout << endl;
}

// Prompts the player for a guess and validates input. Only a single alphabetic
// letter (upper or lower case) is accepted.
void HangmanEngine::playerTurn(vector<char> correctGuesses) {
	string playerInput = "";
	while ((cout << "Enter a letter: \n") && !(cin >> playerInput)
		|| (playerInput.size() > 1) || !isalpha(playerInput[0])) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a single letter from the alphabet." << endl;
	}
	guessedLetter = playerInput[0];
	guessedLetter = toupper(guessedLetter);
	checkLetter(guessedLetter, currentWord, wordLength, correctGuesses);
}

// Checks to see if letter exists in dictionary-chosen word.
void HangmanEngine::checkLetter(char guess, string word, int wordSize, vector<char> guessList) {
	bool isRight = false;
	bool isInList = false;

	for (int element = 0; element < guessList.size(); element++) {
		if (guessList[element] == guess) {
			isInList = true;
			isRight = true;
		}
		else {
			isInList = false;
		}
	}

	for (int letter = 0; letter < wordSize; letter++) {
		if (toupper(word[letter]) == toupper(guess) && !isInList) {
			lettersCorrect.push_back(guess);
			isRight = true;
		}
	}

	if (!isRight) {
		mistakes += 1;
	}
}

// Asks if player would like to play again.
bool HangmanEngine::playAgainCheck() {
	string input = "";

	cout << "Enter X to exit, or any other key to play again." << endl;
	cin >> input;

	if (input == "x" || input == "X") {
		return false;
	}
	else {
		return true;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Adds to the tally of total games played by the player.
void HangmanEngine::addGamePlayed() {
	gamesPlayed += 1;
}

// Returns the current total of the games played by the player.
int HangmanEngine::getGamesPlayed() {
	return gamesPlayed;
}