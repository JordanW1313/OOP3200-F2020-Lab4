#include "StandardDeck.h"
#include <iostream>
#include <cassert>

//StandardDeck& StandardDeck::operator=(const StandardDeck& source)
//{
//	// TODO: insert return statement here
//}

void StandardDeck::CardString()
{
	std::cout << myCardsArray[0][2].GetRank() << " " << myCardsArray[0][2].GetSuit() << std::endl;
}

void StandardDeck::CardsRemaining()
{
	int currentSize = myCardsArray[0].size();
	std::cout << "The deck has " << currentSize << " remaining." << std::endl;
}

void StandardDeck::Initialiaze(PlayingCard *size)
{
	if (size != 0)
	{
		delete[] myCardsArray;
	}



	myCardsArray[52];

	for (int s = 0; s < 4; s++)
	{
		for (int r = 1; r < 14; r++)
		{
			PlayingCard currentCard;
			currentCard.SetRank(PlayingCard::CARD_RANK[r]);
			currentCard.SetSuit(PlayingCard::CARD_SUIT[s]);
			//std::cout << currentCard.GetRank() << " " << currentCard.GetSuit() << std::endl;
			myCardsArray->push_back(currentCard);
		}
	}
}

void StandardDeck::DrawNextCard()
{
	int currentSize = myCardsArray[0].size();

	std::cout << "The next card is the " << myCardsArray[0][0].GetRank() << " of " << myCardsArray[0][0].GetSuit() << "." << std::endl;

	assert(!myCardsArray[0].empty());
	myCardsArray[0].erase(myCardsArray[0].begin());
	myCardsArray[0].resize(currentSize - 1);
}
