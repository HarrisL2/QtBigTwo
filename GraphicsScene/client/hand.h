#ifndef HAND_H
#define HAND_H

#include "basecard.h"

#include <QVector>
#include <QJsonArray>


class Hand
{
public:
    Hand(const QVector<BaseCard*>&);
    Hand(const QVector<int>&);
    Hand(const QJsonArray&);

    void addCard(BaseCard*);
    void removeCard(int);
    void sort();

    int numCards() const;
    int numType(BaseCard::Type) const;
    int numSuit(BaseCard::Suit) const;
    int numColor(BaseCard::Color) const;
    int numNum(int) const;
    QVector<BaseCard*> getCards() const;
    QVector<BaseCard*> getAllNum(int) const;
    QVector<BaseCard*> getAllSuit(BaseCard::Suit) const;
    QVector<BaseCard*> getAllColor(BaseCard::Color) const;
    QJsonArray toJsonArray();

private:
    QVector<BaseCard*> cards;
};

#endif // HAND_H
