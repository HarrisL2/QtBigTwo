#ifndef HAND_H
#define HAND_H

#include "basecard.h"

#include <QVector>


class Hand
{
public:
    Hand(const QVector<BaseCard*>&);
    Hand(const QVector<int>&);

    void addCard(BaseCard*);
    void removeCard(BaseCard*);
    void sort();

    int numCards() const;
    int numType(BaseCard::Type) const;
    int numSuit(BaseCard::Suit) const;
    int numColor(BaseCard::Color) const;
    int numNum(int) const;
    QVector<BaseCard*> getCards() const;

private:
    QVector<BaseCard*> cards;
};

#endif // HAND_H
