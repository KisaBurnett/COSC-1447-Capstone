#ifndef DICTIONARY_H
#define DICTIONARY_H
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

// Opens and reads a file of words, then stores the words in a vector. Words
// are randomly selected for each round.
class Dictionary
{
private:
	string word;
	string pickedWord;
	ifstream wordList;
	vector<string> gameWords;
public:
	Dictionary() {
		word = "";
		pickedWord = "";
	}
	void getWords();
	void showWords();
	string pickWord();
};

#endif