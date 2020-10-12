#include "StandardDeck.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <random>
#include <utility>

// Default constructor implementation.
StandardDeck::StandardDeck()
{
	size = 0;
	Initialize();
}

StandardDeck::~StandardDeck()
{
	myCardsVector->clear();
}
// Copy constructor implementation.
StandardDeck::StandardDeck(const StandardDeck& source)
{
	SetVector(source.myCardsVector[0]);
	size = source.size;
}

// Assignment operator overload.
StandardDeck& StandardDeck::operator=(StandardDeck& source)
{
	this->SetVector(source.myCardsVector[0]);
	this->size = source.size;

	return (*this);
}


void StandardDeck::CardString()
{
	std::cout << myCardsVector[0][2].GetRank() << " " << myCardsVector[0][2].GetSuit() << std::endl;
}

// Returns the size of the cards array.
void StandardDeck::CardsRemaining() const
{
	int currentSize = myCardsVector[0].size();
	std::cout << "The deck currently has " << currentSize << " cards remaining." << std::endl;
}

void StandardDeck::DeckToString()
{
	int deckSize = myCardsVector[0].size();

	std::cout << "Deck Size: " <<  deckSize << std::endl;
	std::cout << "==================================================" << std::endl;

	for (int i = 0; i < deckSize;)
	{
		/*int column = 0;

		if (column > 3)
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i].GetRank() << " " << myCardsVector[0][i].GetSuit() << "(" << i << ")" << "	" << std::endl;
			column = 0;
		}
		else
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i + 1].GetRank() << " " << myCardsVector[0][i + 1].GetSuit() << "(" << i + 1 << ")" << "	";
		}
		if (column > 3)
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i + 1].GetRank() << " " << myCardsVector[0][i + 1].GetSuit() << "(" << i + 1 << ")" << "	" << std::endl;
			column = 0;
		}
		else
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i + 1].GetRank() << " " << myCardsVector[0][i + 1].GetSuit() << "(" << i + 1<< ")" << "	";
		}
		if (column > 3)
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i + 2].GetRank() << " " << myCardsVector[0][i + 2].GetSuit() << "(" << i + 2 << ")" << "	" << std::endl;
			column = 0;
		}
		else
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i + 2].GetRank() << " " << myCardsVector[0][i + 2].GetSuit() << "(" << i + 2 << ")" << "	";
		}
		if (column > 3)
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i + 3].GetRank() << " " << myCardsVector[0][i + 3].GetSuit() << "(" << i + 3 << ")" << "	" << std::endl;
			column = 0;
		}
		else
		{
			std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i + 3].GetRank() << " " << myCardsVector[0][i + 3].GetSuit() << "(" << i + 3 << ")" << "	";
		}*/

		std::cout << std::left << std::setw(8) << std::setfill('-') << myCardsVector[0][i].GetRank() << " " << myCardsVector[0][i].GetSuit() << "(" << i << ")" << "	"
			<< std::left << std::setw(8) << myCardsVector[0][i + 1].GetRank() << " " << myCardsVector[0][i + 1].GetSuit() << "(" << i + 1 << ")" << "	"
			<< std::left << std::setw(8) << myCardsVector[0][i + 2].GetRank() << " " << myCardsVector[0][i + 2].GetSuit() << "(" << i + 2 << ")" << "	"
			<< std::left << std::setw(8) << myCardsVector[0][i + 3].GetRank() << " " << myCardsVector[0][i + 3].GetSuit() << "(" << i + 3 << ")" << "	" << std::endl;
		i += 4;
	}

	std::cout << "==================================================" << std::endl;

}

// Method sets/resets the deck to 52 standard playing cards.
void StandardDeck::Initialize()
{
	// Check if any memory has already been allocated for the playing cards.
	if (size != 0)
	{
		myCardsVector[0].clear(); // Delete memory allocations.
	}

	size = 52; // Set size to number of standard playing cards.

	// Builds 52 playing cards, each having a unique suit and rank combination.
	for (int suit = 0; suit < 4; suit++)
	{
		for (int rank = 1; rank < 14; rank++)
		{
			PlayingCard currentCard; // Card currently being built.
			currentCard.SetRank(PlayingCard::CARD_RANK[rank]);
			currentCard.SetSuit(PlayingCard::CARD_SUIT[suit]);
			//std::cout << currentCard.GetRank() << " " << currentCard.GetSuit() << std::endl;
			myCardsVector->push_back(currentCard); // Allocate the new card into the vector.
		}
	}
}

// Removes the card object at the very beginning of the array, and shifts the rest of the objects' index up 1.
void StandardDeck::DrawNextCard()
{
	int currentSize = myCardsVector[0].size();

	std::cout << "The next card is the " << myCardsVector[0][0].GetRank() << " of " << myCardsVector[0][0].GetSuit() << "." << std::endl;

	assert(!myCardsVector[0].empty());
	myCardsVector[0].erase(myCardsVector[0].begin());
	size = currentSize - 1;
	/*assert(!myCardsVector[0].empty());
	myCardsVector[0].erase(myCardsVector[0].begin());
	myCardsVector[0].resize(currentSize - 1);
	size = currentSize - 1;*/
}

// Removes a random object from the array, and shifts the indices of the following objects by 1 to the left.
void StandardDeck::DrawRandomCard()
{
	int currentSize = myCardsVector[0].size();

	int randNum = rand() % currentSize; // Generate a random int that won't cause out of bounds issues.

	std::cout << "The random card is the " << myCardsVector[0][randNum].GetRank() << " of " << myCardsVector[0][randNum].GetSuit() << "." << std::endl;

	myCardsVector[0].erase(myCardsVector[0].begin()+randNum); // Removes the element at random index.
	/*assert(!myCardsVector[0].empty());
	myCardsVector[0][randNum] = std::move(myCardsVector[0].front());
	myCardsVector[0].erase(myCardsVector[0].begin());
	myCardsVector[0].resize(currentSize - 1);
	size = currentSize - 1;*/
}

void StandardDeck::Shuffle()
{
	std::shuffle(myCardsVector[0].begin(), myCardsVector[0].end(), std::mt19937(std::random_device()())); // Retrieved from https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
	std::cout << "The deck has been shuffled." << std::endl;
}

void StandardDeck::SetVector(std::vector<PlayingCard> vector)
{
	*myCardsVector = std::move(vector);
}
