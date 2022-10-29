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

// Add pre-validated player input to list of correct guesses made this game.
void Player::addCorrectGuess(char input) {
	guessesCorrect.push_back(input);
}

// Return the list of player's correct guesses made this game.
vector<char> Player::guessCorrectList() {
	return guessesCorrect;
}

// Clear the elements stored in the vector of correct guesses.
void Player::resetCorrectGuesses() {
	guessesCorrect.clear();
}

// Add another win by the player to the current total.
void Player::addWin() {
	wins += 1;
}

// Return the current number of wins by the player.
int Player::getWins() {
	return wins;
}

// Calculates and displays the total numbers of games played, won, and lost by the player.
void Player::playerStats(int games) {
	int gamesWon = getWins();
	int gamesLost = (games - gamesWon);

	cout << "You played " << games << " rounds, won "
		<< gamesWon << " rounds, and lost " << gamesLost << " rounds." << endl;
}