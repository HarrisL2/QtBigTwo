#ifndef COMBINATION_H
#define COMBINATION_H

#include <QVector>
#include <QJsonArray>
#include "basecard.h"

/*
 * Combination is a class that provides a data structure that
 * validates and creates plays in a game of Big Two/TwUNO. It
 * contains a size-sorted vector of cards, while also
 * perserving the original played order.
 */

class Combination
{
public:
    enum class Type {
        PASS,
        SINGLE,
        PAIR,
        TRIPLE,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH
    };

    static Combination* createCombination(const QJsonArray&);
    static Combination* createCombination(QVector<int>);
    static Combination* createCombination(QVector<BaseCard*>);


    QVector<BaseCard*> getCards() const;
    QVector<BaseCard*> getSorted() const;
    BaseCard* getFirstCard() const;
    BaseCard* getLastCard() const;
    Type getType() const;
    int size() const;

    QJsonArray toJsonArray();


private:
    Combination(QVector<BaseCard*>, Type);
    Type type;
    QVector<BaseCard*> cards;
    QVector<BaseCard*> sorted;
};

bool operator>(const Combination& lhs, const Combination& rhs);

#endif // COMBINATION_H
