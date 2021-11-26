#include "playingcard.h"

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

//inline bool operator==(const PlayingCard& lhs, const PlayingCard& rhs){return (lhs.getID() == rhs.getID());}
//inline bool operator!=(const PlayingCard& lhs, const PlayingCard& rhs){return !operator==(lhs,rhs);}
//inline bool operator< (const PlayingCard& lhs, const PlayingCard& rhs){return (lhs.getID() < rhs.getID());}
//inline bool operator> (const PlayingCard& lhs, const PlayingCard& rhs){return  operator< (rhs,lhs);}
//inline bool operator<=(const PlayingCard& lhs, const PlayingCard& rhs){return !operator> (lhs,rhs);}
//inline bool operator>=(const PlayingCard& lhs, const PlayingCard& rhs){return !operator< (lhs,rhs);}
