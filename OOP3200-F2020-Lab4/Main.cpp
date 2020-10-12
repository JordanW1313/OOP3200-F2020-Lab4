/****************************************************************
* Name: Jordan Wriker & Ahmed Rizvi
* Date: 11th October, 2020
* Course: OOP-3200
* File: OOP3200-F2020-Lab4
* Purpose: The purpose of this lab is to create a collection class
*		   that contains PlayingCard objects. In this case, the new
*		   class contains 52 PlayingCard, as seen from a typical deck
*		   of playing cards.
*
******************************************************************/

#include <ctime>
#include <iostream>
#include "StandardDeck.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	//srand(time(nullptr)); // seed the random number generator


	// Create a deck for testing.
	StandardDeck test_deck1;

	// Show the deck object as initialized
	test_deck1.DeckToString();

	Pause();

	// Draw the next card and show it
	//test_deck1.DrawNextCard();
	test_deck1.DrawNextCard();
	test_deck1.DrawNextCard();

	test_deck1.CardsRemaining();

	Pause();

	// Draw a random card and show it
	test_deck1.DrawRandomCard();
	// Show the deck with the remaining cards
	test_deck1.CardsRemaining();

	Pause();

	// Shuffle the deck and show the result
	test_deck1.Shuffle();
	test_deck1.DeckToString();
	std::cout << std::endl << std::endl;

	Pause();
	
	// Reset the deck and show the result
	test_deck1.Initialize();
	test_deck1.DeckToString();
	std::cout << std::endl << std::endl;

	Pause();
	
	// Show copy constructor and = overload.
	test_deck1.Shuffle();
	StandardDeck test_deck2 = test_deck1;
	StandardDeck test_deck3;
	test_deck2 = test_deck3;

	test_deck2.DeckToString();
}


