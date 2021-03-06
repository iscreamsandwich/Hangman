// Hangman.cpp : Defines the entry point for the console application.
//LET'S PLAY HANGMAN. The program pulls a word randomly from a file and you gotta guess it in a certain number of turns.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void changeLetter(char, string, string&);	//if a guess is correct, add that letter
bool checkGuess(char, string, string&);		//checks if a guess is wrong and returns a bool
bool checkGameStatus(string&, string&);		//checks if all the guessed letters match the hidden word
void drawMan(int);							//draws hangman board

int main()
{
	bool gameOver = false;
	char guessedLetter;
	int incorrectGuessCounter = 0;
	const int maxGuesses = 6;

	//open file to read from
	ifstream inFile;
	inFile.open("wordlist.txt");

	if (!inFile.is_open()) {
		cout << "Error reading file!";
		return 1;
	}
	//

	//randomly pull word from file
	string word;

	srand(time(0));
	int wordIndex = rand() % 60 + 1;

	for (int i = 0; i < wordIndex; i++) {
		inFile >> word;
	}
	//

	//set blank string guessedAnswer to length of actual answer
	string guessedAnswer;
	for (int i = 0; i < word.length(); i++) {
		guessedAnswer += "_";
	}
	//

	//while game isn't over, continue to ask for letters
	while (!gameOver) {
		cout << "\nGuess a letter: " << guessedAnswer << "\n";
		cin >> guessedLetter;
		changeLetter(guessedLetter, word, guessedAnswer); //check if letter is found in word and if so, add that letter to blank guessedAnswer

		if (checkGameStatus(word, guessedAnswer)) { //if game over is true, end game with a win and output answer
			gameOver = true;
			cout << "Answer: " << word << "\n";
			cout << "\nYou got it! Now go outside into the real world.\n";
			system("pause");
		}

		if (incorrectGuessCounter == maxGuesses)			//if max number of guesses has been reached
			gameOver = true;

		if (!checkGuess(guessedLetter, word, guessedAnswer)) {	//if guessed letter is not found in word, increment incorrect guess counter
			incorrectGuessCounter++;
		}

		cout << "\n\n\n";
		drawMan(incorrectGuessCounter);			//output hangman game
	}

	if (incorrectGuessCounter > maxGuesses - 1) {	//if gameOver is false but max number of guesses has been reached, game over, output answer
		cout << "You ran out of guesses! Better luck next time.\n"; 
		cout << "The word was " << word << endl;
		system("pause");
	}

    return 0;
}

void changeLetter(char letter, string answer, string& guess) {
	for (int i = 0; i < answer.length(); i++) {
		if (answer[i] == letter) {
			guess[i] = letter;
		}
	}
}

bool checkGuess(char letter, string answer, string& guess) {
	for (int i = 0; i < answer.length(); i++) {
		if (answer[i] == letter) {
			return true;
		}
	}
	return false;
}

bool checkGameStatus(string& answer, string& guess) {
	if (answer == guess)
		return true;
	return false;
}

void drawMan(int turn) {
	switch (turn) {
	case 1:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\tO\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	case 2:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\tO\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	case 3:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\tO\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	case 4:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\tO\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t/\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	case 5:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\tO\n";
		cout << "\t\t\t\t|\t      --|\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t/\\\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	case 6:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\tO\n";
		cout << "\t\t\t\t|\t      --|--\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t/\\\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	case 7:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\tO\n";
		cout << "\t\t\t\t|\t      --|--\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t/\\\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	default:
		cout << "\t\t\t\t________________\n";
		cout << "\t\t\t\t|\t\t|\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|\t\t\t\n";
		cout << "\t\t\t\t|__________________\n\n";
		break;
	}

}