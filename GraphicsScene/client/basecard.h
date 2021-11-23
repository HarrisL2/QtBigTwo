#ifndef BASECARD_H
#define BASECARD_H


class BaseCard
{
public:
    enum class Type {
        PLAYING,
        UNO
    };

    enum class Suit {
        DIAMOND,
        CLUB,
        HEART,
        SPADE
    };

    enum class Color {
        RED,
        GREEN,
        BLUE,
        YELLOW
    };

    virtual ~BaseCard() = default;

    virtual BaseCard::Type getType() const = 0;
    virtual BaseCard::Suit getSuit() const = 0;
    virtual void cardEffect() const = 0;
    virtual int getNumber() const = 0;
    virtual int getID() const = 0;



protected:
    BaseCard();
};

#endif // BASECARD_H
