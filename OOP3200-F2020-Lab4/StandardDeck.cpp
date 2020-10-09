#include "StandardDeck.h"
#include <iostream>
#include <iomanip>
#include <cassert>

//StandardDeck& StandardDeck::operator=(const StandardDeck& source)
//{
//	// TODO: insert return statement here
//}

StandardDeck& StandardDeck::operator=(StandardDeck& source)
{
	this->SetVector(source.myCardsVector[0]);
	this->size = source.size;

	return *this;
}

void StandardDeck::CardString()
{
	std::cout << myCardsVector[0][2].GetRank() << " " << myCardsVector[0][2].GetSuit() << std::endl;
}

void StandardDeck::CardsRemaining()
{
	int currentSize = myCardsVector[0].size();
	std::cout << "The deck has " << currentSize << " remaining." << std::endl;
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

void StandardDeck::Initialiaze(/*PlayingCard *size*/)
{
	if (size != 0)
	{
		myCardsVector[0].clear();
	}

	size = 52;

	for (int s = 0; s < 4; s++)
	{
		for (int r = 1; r < 14; r++)
		{
			PlayingCard currentCard;
			currentCard.SetRank(PlayingCard::CARD_RANK[r]);
			currentCard.SetSuit(PlayingCard::CARD_SUIT[s]);
			//std::cout << currentCard.GetRank() << " " << currentCard.GetSuit() << std::endl;
			myCardsVector->push_back(currentCard);
		}
	}
}

void StandardDeck::DrawNextCard()
{
	int currentSize = myCardsVector[0].size();

	std::cout << "The next card is the " << myCardsVector[0][0].GetRank() << " of " << myCardsVector[0][0].GetSuit() << "." << std::endl;

	assert(!myCardsVector[0].empty());
	myCardsVector[0].erase(myCardsVector[0].begin());
	myCardsVector[0].resize(currentSize - 1);
	size = currentSize - 1;
}

void StandardDeck::DrawRandomCard()
{
	int currentSize = myCardsVector[0].size();

	int randNum = rand() % 52 + 1;

	std::cout << "The random card is the " << myCardsVector[0][randNum].GetRank() << " of " << myCardsVector[0][randNum].GetSuit() << "." << std::endl;

	assert(!myCardsVector[0].empty());
	myCardsVector[0][randNum] = std::move(myCardsVector[0].front());
	myCardsVector[0].erase(myCardsVector[0].begin());
	myCardsVector[0].resize(currentSize - 1);
	size = currentSize - 1;
}

void StandardDeck::SetVector(std::vector<PlayingCard> vector)
{
	*myCardsVector = vector;
}
