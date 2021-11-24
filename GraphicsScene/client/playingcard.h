#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include "basecard.h"

class PlayingCard : public BaseCard
{
public:
    explicit PlayingCard(int);

    ~PlayingCard() = default;

    BaseCard::Type getType() const;
    BaseCard::Suit getSuit() const;
    int getNumber() const;
    int getID() const;

private:
    int ID;
    int number;

    BaseCard::Suit suit;
};

#endif // PLAYINGCARD_H
