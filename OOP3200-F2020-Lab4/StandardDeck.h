/** OOP3200. F2020. StandardDeck.h
 *
 *  In this lab you will create your own collection class called StandardDeck, which
 *	will 'contain' objects of the PlayingCard class.  The intent of the class is to
 *	represent a standard deck of 52 cards that might be useful in a card game type
 *	application.  
 *
 *	@author		Thom MacDonald
 *	@author		Tom Tsiliopoulos
 *	@version	2020.10
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include "PlayingCard.h"
#include <vector>

class StandardDeck
{
public:

	// Initialization:
	StandardDeck() 
	{
		size = 0;
		Initialiaze();
	}

	// Rule of three:
	~StandardDeck() { delete[] myCardsVector; } // destructor
	StandardDeck(const StandardDeck& source); // copy constructor
	StandardDeck& operator=(StandardDeck& source); // assignment operator

	// Accessors:
	void CardString();

	void CardsRemaining();

	void DeckToString();

	// Mutators:
	void Initialiaze(/*PlayingCard* card*/);

	void DrawNextCard();

	void DrawRandomCard();

	void SetVector(std::vector<PlayingCard> vector);

private:
	std::vector<PlayingCard> myCardsVector[1];
	//PlayingCard *size;
	int size;
};

#endif /* defined (__STANDARD_DECK__) */

