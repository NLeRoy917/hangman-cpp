# hangman-cpp
A c++ program that plays hangman with the user

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
