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
	srand(time(nullptr)); // seed the random number generator

	// create a deck
	StandardDeck newDeck;

	// Show the deck object as initialized
	newDeck.DeckToString();

	newDeck.DrawNextCard();
	newDeck.DrawNextCard();
	newDeck.DrawNextCard();

	newDeck.CardsRemaining();

	newDeck.Shuffle();
	//newDeck.DeckToString();
	//Pause();

	//StandardDeck deck2;

	//deck2 = newDeck;

	//deck2.CardsRemaining();

	//Pause();
	
	// Draw the next card and show it

	// Draw a random card and show it
	
	// Show the deck with the remaining cards

	// Shuffle the deck and show the result

	// Reset the deck and show the result
}


