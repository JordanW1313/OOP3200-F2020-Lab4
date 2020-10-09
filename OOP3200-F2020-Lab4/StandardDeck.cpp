#include "StandardDeck.h"

StandardDeck& StandardDeck::operator=(const StandardDeck& source)
{
	// TODO: insert return statement here
}

void StandardDeck::CardString()
{
	
}

void StandardDeck::Initialiaze(PlayingCard *size)
{


	if (size != 0)
	{
		delete[] myCardsArray;
	}

	size = 52;

	for (int s = 0; s < 3; s++)
	{
		for (int r = 1; r < 13; r++)
		{
			PlayingCard currentCard;
			currentCard.SetRank(PlayingCard::CARD_RANK[r]);
			currentCard.SetSuit(PlayingCard::CARD_SUIT[s]);
			myCardsArray->push_back(currentCard);
		}
	}
}
