// Being Script //

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

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= //

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


/*
This function counts the number of words in the text-file that stores potential
mystery words. It reads each line, increments a counter, and returns that value.
This function is necessary as it allows us to select a random number between
1 and the line-count, to select a random word.

Inputs:
	None

Returns:
	int cnt : integer storing number of lines in file.

*/

int count_words() {

	ifstream word_list("word_list.txt");
	string line;
	int cnt = 0;

	while (getline(word_list,line)) {

		cnt++;
		
	}

	return cnt++;
}

/*
This function will get a random number that can be used to select a random word
from our word list.

Inputs:
	int num_words : number of words in our word list file

Returns:
	int ran_num : random number between 1 and num_words

*/

int getRand(int num_words) {

	int rand_num;

	rand_num = (rand() % num_words) + 1;

	return rand_num;
}

/*
Function to select a word from the word_list file. It opens the file stream,
initializes a counter, and reads the file line by line. It increments the
counter for each line read, and once the counter reaches the random number
supplied to the function, it returns that line/word.

Inputs:
	int rand_num : random number between 1 and number of words in file

Returns:
	string line : word in the text file.

*/

string getWord(int rand_num) {

	ifstream word_list("word_list.txt"); // Open file
	string line; // Initialize line string.
	int cnt = 0; // Initialize counter.

	while (getline(word_list,line)) { // Returns true until EOF

		if (cnt == rand_num) { // Once reached the random number
			return line; // Return that word.
		}

		cnt++;
		
	}

	return line; // After all else, just return the last word.
}

/*
Function will prompt the user for a character to guess. It simply
takes in the character, and will return it.

Inputs:
	None

Returns:
	Nothing char guess_char : character guessed by user.

*/

char get_guess() {

	char guess_char;

	cout << "\nGuess a letter: ";
	cin >> guess_char; // IO in stream
 
	return guess_char; // Return that character
}


/*
The game begins with a greeting. This function prints and starts that. It begins by
clearing the screen, flushing the system, and welcoming the user. It prints
a blank board with the blank guess_array and alphabet underneath. Finally,
it primpts the user to hit enter, and will only continue until that is done.

Inputs:
	char guess_array[] : initialized blank guess_array to be printed.
	int len_word : length of the mystery word.
	char alphabet[] : full alphabet to be printed.

Returns:
	Nothing (void)

*/

void greeting(char guess_array[], int len_word, char alphabet[]) {

	char enter_any; // User's character guess.

	system("clear"); // Clear the screen (aid visibility)
	cout << flush; // Force clear by flushing system IO

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

	getchar(); // Wait for user-input of enter

	return; // Return nothing
}


/*
FUnction which will ensure that this is a vlaid guess before continuing with the
game. It makes sure that the user has not already guessed the letter and the
character is valid. First it checks for a '-' char. This returns a false and 
prompts the user that it is an invalid character. Then it checks each index in 
the alphabet. If the letter has been found, that indicates that the letter has
not been guessed and it will change that index/letter to a '-'. The function
then returns true to indicate that the letter was a valid guess. If the guessed
letter does NOT match any letter/character in the laphabet[] array, we know that
the letter was already guessed, or is an invlaid character (number, symbol, etc.).
This returns a false indicating it is not a valid input and prompts the user saying
that the letter has already been guessed, or it is an invalid guess.

Inputs:
	char guess_char : the guessed character inputted by the user.
	char alphabet[] : current state of the alphabet array. When changed in
					  function, changes in main () as arrays are passed by
					  address

Returns:
	 bool (true or false)
*/

bool check_guess(char guess_char, char alphabet[]) {
	if (guess_char == '-') {
		cout << "Invlaid character" << endl;
		return 0;
	}

	guess_char = toupper(guess_char); // Force to upper-case for checking

	// Check alphabet
	for (int i = 0; i < 26; i++) {

		if (alphabet[i] == guess_char) { // If the guess_char equals the alphabet index
			alphabet[i] = '-'; // Change the found letter to '-', to reflect it being used
			return 1; // Return valid input.
		}
	}

	cout << "Letter already guessed or invlid character!" << endl;
	return 0; // returns false if not found in alphabet or guess_array

}

/*
After the character has been guessed, we need to update our guess_arrayp[]. This function
serves two purposes: Update the array, and return a boolean value indicating that the word
contains the guessed letter. It checks the word each letter at a time, and if the guessed
character is found, it will add the character to the guess_array at the index, and set
the in_word flag to 1 (true).

Inputs:
	string word : mystery word being guessed
	char guess_char : character guessed by the user
	char guess_array[] : array that contains the state of our guessing
	int len_word : length of the mystery word
	char alphabet[] : current state of alpabet array.

Returns:
	bool in_word, true or false.

*/

bool update_word(string word, char guess_char, char guess_array[], int len_word, char alphabet[]) {

	bool in_word = 0; // Initialise the flag

	// toupper used to remove any discrepencies of lower-case
	for (int i = 0; i < len_word; i++) { // For each character in the word
		if (toupper(word[i]) == toupper(guess_char)) { // Is the character equal to the guessed character?
			guess_array[i] = toupper(guess_char); // If so, change the guess_array index to that character
			in_word = 1; // Change to true to reflect fact that character is in the word.

		}
	
	}
	return in_word; // Is it in the word or not? Return that value
}


/*
This funciton simply checks the state of the game to see if the user has won.
The user will have won when all the characters in the guess array are filled-In,
or in other words all blanks '_' are removed.

Inputs:
	char guess_array[] : state of the guess_array
	int len_word : length of our word.

Returns:
	boolean value (true or false)

*/

bool check_win(char guess_array[], int len_word) {

	for (int i = 0; i < len_word; i++) { //For each index in our array
		if (guess_array[i] == '_') { // Is that index a blank?
			return 0; // If so, false, user has not won
		}
	}
	// gotten through for loop with no blanks found...
	return 1; // Return true.
}


// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= //


// MAIN FUNCTION //
int main() {

	// Seed the random number generator
	srand(time(NULL));

	// Initializations
	string word;
	int guess_num = 0;
	int rand_num;
	int num_words;
	bool in_word;
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
						 'H', 'I', 'J', 'K', 'L', 'M', 'N',
						 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
						 'V', 'W', 'X', 'Y', 'Z' };
	
	// Game Set Up
	num_words = count_words();
	rand_num = getRand(num_words);
	word = getWord(rand_num);
	int len_word = 	len_word = word.length();;
	char guess_array[len_word];
	initialize_guess_array(guess_array, len_word);


	// Begin the game
	greeting(guess_array, len_word, alphabet);


	// Loop will always break at some point
	while(true) { 
		// User still has guesses left? 
		if (guess_num < 7) {


			char guess_char = get_guess(); // prompt user and get character
			while (!check_guess(guess_char, alphabet)) { // Make sure user gave valid input
				guess_char = get_guess(); // try again if invalid input
			}

			// update the word, and check for the presence of the caracter in the word.
			in_word = update_word(word, guess_char, guess_array, len_word, alphabet);

			if (!in_word) { // If not in word add strike/increment guesses.
				guess_num++;
				cout << "Letter not in mystery word!" << endl; // Tell user what happened

			}
			
			system("clear"); // clear the screen for the user
			cout << flush; // Flush stream
			print_board(guess_num, guess_array, len_word, alphabet);


			if (check_win(guess_array,len_word)) { // Has the user won?
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


	return 0; // End of main and end of script

}


// END SCRIPT //