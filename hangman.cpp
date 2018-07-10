/*
hangman.cpp
Author: Nathan LeRoy
Creation Date: July 9th, 2018
Version: 1.0.0


Hangman! This c++ program will play hangman with the user, having the user
guess the word. The user is given a mystery word to guess and the entire alphabet
to choose from. The user has 7 guesses (or strikes) to figure out the word by 
guessing letters in the word. A strike is given for an incorrect guess (The letter 
is not in the word). Once a letter is guessed, the user can not guess that letter
again (the program will prompt them if this occurs), and a strike will not be
deducted.

The game continues until the user has run out of guesses, or the mystery word has been
guessed (All letters are filled in).

The program also features the classic hangman "hanger" which adds parts of our drawn
man to indicate how many guesses have been used. Below this hanger is the mystery word
with any correct guesses filled in. Below that is the alphabet. Any letters already guessed
are replaced with a ' - ' character. 


*/

// Bring in necessary libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

// Function Definitions //

/*
This function will print the character array that store the users correct guesses.
It is simple, and just prints the array, one index at a time with a space in between.

Inputs:
	char guess_array[] : array that stores the guesses
	int len_word : integer that stores the length of the word
Returns:
	Nothing (void)

*/
void print_guess_array(char guess_array[], int len_word) {

	cout << endl; // New Line

	for(int i = 0; i < len_word; i++) { // For each index

		cout << guess_array[i] << " "; // Primt with a space
	}

	cout << endl; // New lines
	cout << endl;

	return; // returns nothing
}


/*
This function is almost identical to print_guess_array. It prints the alphabet array.
It only requires the alphabet array since the length of that array will never NOT
be 26.

Inputs:
	char alphabet[] : array that stores each letter of the alphabet, and 
					  its state in the game.
Returns:
	Nothing (void)

*/
void print_alphabet(char alphabet[]) {

	for(int i = 0; i < 26; i++) { // For each index

		cout << alphabet[i];
		cout << " "; // Print with space in betweeb
		if (i == 5 || i == 11 || i == 17 || i == 23) { // New line formating
			cout << endl;
		}
	}

	return;
}

/*
This is a long function, however its purpose is relatively simple. It is responsible for
printing the state of our 'Game Board'. After the game board is called, it calls the
necessray functions to print the guess_array and the alphabet array. This is a void
function, since it does not need to return anything.

Inputs:
	int guess : number of guesses used
	char guess_array[] : The array that stores the state of the guessed word
	int len_word : integer that stores the number of characters in the word
	char alphabet[] : character array that stores the current state of the alphabet.

Returns:
	Nothing (void)

*/

void print_board(int guess, char guess_array[], int len_word, char alphabet[]) {
	

	if (guess == 0) {
		cout << "Guesses Left: " << 7 << endl;
		cout << " ________\n "
				"|       |\n"
				" | \n"
				" | \n"
				" | \n"
				" | \n"
				" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet);

	}

	if (guess == 1) {
		cout << "Guesses Left: " << 6 << endl;
		cout << " ________\n "
				"|       |\n"
				" |       O\n"
				" | \n"
				" | \n"
				" | \n"
				" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet);
	}

	if (guess == 2) {
		cout << "Guesses Left: " << 5 << endl;
		cout << " ________\n "
				"|       |\n"
				" |       O\n"
				" |       |\n"
				" |       |\n"
				" | \n"
				" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet); 
	}

	if (guess == 3) {
		cout << "Guesses Left: " << 4 << endl;
		cout << " ________\n "
				"|       |\n"
				" |       O\n"
				" |     __|\n"
				" |       |\n"
				" | \n"
				" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet);
	}

	if (guess == 4) {
		cout << "Guesses Left: " << 3 << endl;
		cout << " ________\n "
				"|       |\n"
				" |       O\n"
				" |     __|__\n"
				" |       |\n"
				" | \n"
				" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet);
	}

	if (guess == 5) {
		cout << "Guesses Left: " << 2 << endl;
		cout << " ________\n "
				"|       |\n"
				" |       O\n"
				" |     __|__\n"
				" |       |\n"
				" | \n"
				" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet);
	}

	if (guess == 6) {
		cout << "Guesses Left: " << 1 << endl;
		cout << " ________\n "
				"|       |\n"
				" |       O\n"
				" |     __|__\n"
				" |       |\n"
				" |      /\n"
				" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet);			
	}

	if (guess == 7) {
		cout << endl << "Guesses Left: " << 0 << endl;
		cout << " ________\n "
			"|       |\n"
			" |       O\n"
			" |     __|__\n"
			" |       |\n"
			" |      / \\ \n"
			" |________\n";

		print_guess_array(guess_array, len_word);
		print_alphabet(alphabet);
	}

	return; // Return no value

}


/*
This function will initialize and populate the guess array. In main(), the char
array, guess_array is initialized/given a spot in memory with a defined length,
but does not have any meaningful data inside. We must populate it with blanks
or underscores '_'. For each index in teh array, assign it as the underscore char.
Since arrays in C++ are passed by address, when we alter the array in the
funciton, it gets altered in main too.

Inputs:
	char guess_array : array that stores the guesses
	int len_word : integer that stores the length of the word

Returns:
	Nothing (void)

*/

void initialize_guess_array(char guess_array[], int len_word) {

	for(int i = 0; i < len_word; i++) {

		guess_array[i] = '_';
	}

	return; // Return nothing
}




int count_words() {

	ifstream word_list("word_list.txt");
	string line;
	int cnt = 0;

	while (getline(word_list,line)) {

		cnt++;
		
	}

	return cnt++;
}

int getRand(int num_words) {
	int rand_num;
	rand_num = (rand() % num_words) + 1;

	return rand_num;
}

string getWord(int rand_num) {

	ifstream word_list("word_list.txt");
	string line;
	int cnt = 0;

	while (getline(word_list,line)) {

		if (cnt == rand_num) {
			return line;
		}

		cnt++;
		
	}

	return line;
}

char get_guess() {

	char guess_char;

	cout << "\nGuess a letter: ";
	cin >> guess_char;

	return guess_char;
}

void greeting(char guess_array[], int len_word, char alphabet[]) {

	char enter_any;

	system("clear");
	cout << flush;
	cout << "Welcome! This is the game of hangman. You have 7 tries to guess the mystery word :o" << endl << endl;
	cout << "Your mystery word has " << len_word << " characters and no spaces." << endl;
	cout << " ________\n "
			"|       |\n"
			" | \n"
			" | \n"
			" | \n"
			" | \n"
			" |________\n";

	print_guess_array(guess_array, len_word);
	print_alphabet(alphabet);

	cout << endl << "Press ENTER to continue . . .";

	getchar();


}

bool check_guess(char guess_char, char alphabet[]) {
	if (guess_char == '-') {
		cout << "Invlaid character" << endl;
		return 0;
	}

	guess_char = toupper(guess_char);

	// Check alphabet
	for (int i = 0; i < 26; i++) {

		if (alphabet[i] == guess_char) {
			alphabet[i] = '-';
			return 1;
		}
	}

	cout << "Letter already guessed or invlid character!" << endl;
	return 0; // returns false if not found in alphabet or guess_array

}

bool update_word(string word, char guess_char, char guess_array[], int len_word, char alphabet[]) {
	bool in_word = 0;
	for (int i = 0; i < len_word; i++) {
		if (toupper(word[i]) == toupper(guess_char)) {
			guess_array[i] = toupper(guess_char);
			in_word = 1;

		}
	
	}
	return in_word;
}

bool check_win(char guess_array[], int len_word) {

	for (int i = 0; i < len_word; i++) {
		if (guess_array[i] == '_') {
			return 0;
		}
	}

	return 1;
}

int main() {

	// Seed the random number generator
	srand(time(NULL));

	string word;
	int guess_num = 0;
	int rand_num;
	int num_words;
	bool in_word;
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
						 'H', 'I', 'J', 'K', 'L', 'M', 'N',
						 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
						 'V', 'W', 'X', 'Y', 'Z' };
	

	num_words = count_words();
	rand_num = getRand(num_words);
	word = getWord(rand_num);

	int len_word = 	len_word = word.length();;
	char word_array[len_word];
	char guess_array[len_word];

	for (int i = 0; i < len_word; i++) {
		word_array[i] = word[i];
	}

	initialize_guess_array(guess_array, len_word);

	greeting(guess_array, len_word, alphabet);


	while(true) {
		if (guess_num < 7) {

			char guess_char = get_guess();

			while (!check_guess(guess_char, alphabet)) {
				guess_char = get_guess();

			}

			in_word = update_word(word, guess_char, guess_array, len_word, alphabet);

			if (!in_word) {
				guess_num++;
				cout << "Letter not in mystery word!" << endl;

			}
			
			system("clear");
			cout << flush;

			print_board(guess_num, guess_array, len_word, alphabet);

			if (check_win(guess_array,len_word)) {
				cout << endl << endl << "Congrats! You guessed the mystery word!" << endl;

				break;
			}
		}

		if (guess_num >= 7) {

			system("clear");
			cout << flush;

			print_board(guess_num, guess_array, len_word, alphabet);
			cout << endl << "Sorry! You are out of guesses." << endl;
			cout << "The word was: " << word << endl;
			break;

			
		}
	}


	return 0;

}
