#ifndef BASECARD_H
#define BASECARD_H

/*
 * BaseCard is an abstract base class for the creation of
 * card-based data structures. It has pure virtual functions
 * that return specific information about the cards such as
 * numbers and colors. There is also an overloaded operator
 * that acts as a validator for whether the lhs card can be
 * played after the rhs card.
 */

class BaseCard
{
public:
    enum class Type {
        PLAYING,
        UNO
    };

    enum class Suit {
        NOSUIT,
        DIAMOND,
        CLUB,
        HEART,
        SPADE
    };

    enum class Color {
        NOCOLOR,
        RED,
        GREEN,
        BLUE,
        YELLOW
    };

    enum class Effect {
        NOEFFECT,
        REVERSE,
        SKIP,
        DRAWTWO
    };

    virtual ~BaseCard() = default;

    virtual BaseCard::Type getType() const = 0;
    virtual BaseCard::Suit getSuit() const;
    virtual BaseCard::Color getColor() const;
    virtual BaseCard::Effect getEffect() const;
    virtual int getNumber() const = 0;
    virtual int getID() const = 0;



protected:
    BaseCard();
};

bool operator>(const BaseCard& lhs, const BaseCard& rhs);

#endif // BASECARD_H
