#include "playingcard.h"


/*
 *  PlayingCards::PlayingCard(int id)
 *  @funct: create a playing card from given id
 *  @param: N/A
 *  @return: N/A
 */


PlayingCard::PlayingCard(int id) :
    ID(id),
    number((id-1)/4 + 3 > 13 ? (id-1)/4 - 10: (id-1)/4 + 3)
{
    suit = static_cast<BaseCard::Suit>( id%4 == 0? 4 : id%4 );
}

BaseCard::Type PlayingCard::getType() const {
    return BaseCard::Type::PLAYING;
}

BaseCard::Suit PlayingCard::getSuit() const {
    return suit;
}

int PlayingCard::getNumber() const {
    return number;
}

int PlayingCard::getID() const {
    return ID;
}
