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

void declaration();
void HangmanGame();

int main()
{
    declaration();
    HangmanGame();
}

// Provides a description of the program.
void declaration() {
    string line01 = "+-------------------------------------------------------------------------+\n";
    string line02 = "|Application Name: Capstone Project - Hangman                             |\n";
    string line03 = "|File Names: capstone_KisaBurnett.cpp, HangmanBody.h, HangmanEngine.h,    |\n";
    string line04 = "|            Dictionary.h, Player.h, HangmanBody.cpp, HangmanEngine.cpp,  |\n";
    string line05 = "|            Dictionary.cpp, Player.cpp                                   |\n";
    string line06 = "|Author/Creator: Kisa Burnett                                             |\n";
    string line07 = "|Description: Uses four classes to play a game of hangman.                |\n";
    string line08 = "+-------------------------------------------------------------------------+\n\n";

    string declaration = line01 + line02 + line03 + line04 + line05 + line06 + line07 + line08;

    cout << declaration;
}

// Instantiates and runs the Hangman application.
void HangmanGame() {
    HangmanEngine game;
    game.play();
}