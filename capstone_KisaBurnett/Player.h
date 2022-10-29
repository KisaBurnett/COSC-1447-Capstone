#ifndef PLAYER_H
#define PLAYER_H
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

// Manages information about the Hangman player, including the correct guesses
// made in a given round, and the numbers of games won by the player.
class Player
{
private:
	int wins;
	vector<char> guessesCorrect;
public:
	Player() {
		wins = 0;
	}
	void addCorrectGuess(char input);
	vector<char> guessCorrectList();
	void resetCorrectGuesses();
	void addWin();
	int getWins();
	void playerStats(int games);
};
#endif