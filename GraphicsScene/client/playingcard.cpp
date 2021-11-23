#include "playingcard.h"

PlayingCard::PlayingCard(int num) :
    ID(num),
    number(num%13 == 0? 13 : num%13)
{
    suit = static_cast<BaseCard::Suit>( num%4 == 0? 4 : num%4 );
}

BaseCard::Type PlayingCard::getType() const {
    return BaseCard::Type::PLAYING;
}

BaseCard::Suit PlayingCard::getSuit() const {
    return suit;
}

void PlayingCard::cardEffect() const {}

int PlayingCard::getNumber() const {
    return number;
}

int PlayingCard::getID() const {
    return ID;
}

inline bool operator==(const PlayingCard& lhs, const PlayingCard& rhs){return (lhs.getID() == rhs.getID());}
inline bool operator!=(const PlayingCard& lhs, const PlayingCard& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const PlayingCard& lhs, const PlayingCard& rhs){return (lhs.getID() < rhs.getID());}
inline bool operator> (const PlayingCard& lhs, const PlayingCard& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const PlayingCard& lhs, const PlayingCard& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const PlayingCard& lhs, const PlayingCard& rhs){return !operator< (lhs,rhs);}
