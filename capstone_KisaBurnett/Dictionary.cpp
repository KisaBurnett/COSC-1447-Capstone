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

// Reads a list of words from a file into a vector, which will act as the
// dictionary for the hangman game.
void Dictionary::getWords() {
	wordList.open("words.txt");
	if (wordList) {
		while (wordList >> word) {
			gameWords.push_back(word);
		}
		wordList.close();
	}
	else {
		cout << "I'm sorry, there's an issue with the provided list of words." << endl;
		cout << "Please check your file and try again." << endl;
	}
}

// Selects and returns a word from the game dictionary.
string Dictionary::pickWord() {
	unsigned seed = time(0);
	int start = 0;
	int stop = (gameWords.size() - 1);
	int element = 0;

	srand(seed);

	element = (rand() % (stop - start + 1) + start);

	pickedWord = gameWords[element];
	return pickedWord;
}

// Displays words stored in game dictionary.
void Dictionary::showWords() {
	int length = gameWords.size();

	for (int word = 0; word < length; word++) {
		cout << gameWords[word] << endl;
	}
}