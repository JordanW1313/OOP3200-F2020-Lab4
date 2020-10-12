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


	// create a deck
	StandardDeck test_deck1;

	// Show the deck object as initialized
	test_deck1.DeckToString();

	Pause();

	// Draw the next card and show it
	test_deck1.DrawNextCard();
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

	// Reset the deck and show the result
	test_deck1.Initialize();
	test_deck1.DeckToString();

	// Show assignment operator working
	StandardDeck test_deck2;
	test_deck2 = test_deck1;

	test_deck2.DeckToString();
}


