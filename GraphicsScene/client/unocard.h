#ifndef UNOCARD_H
#define UNOCARD_H

#include "basecard.h"

/*
 * UNOCard inherits from BaseCard to implement a
 * standard UNO Card.
 */

class UNOCard : public BaseCard
{
public:
    explicit UNOCard(int);

    ~UNOCard() = default;

    BaseCard::Type getType() const;
    BaseCard::Color getColor() const;
    BaseCard::Effect getEffect() const;
    int getNumber() const;
    int getID() const;

private:
    int ID;
    int number;

    BaseCard::Color color;
};

#endif // UNOCARD_H
