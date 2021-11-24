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

#endif // BASECARD_H
