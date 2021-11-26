#ifndef COMBINATION_H
#define COMBINATION_H

#include <QVector>
#include "basecard.h"

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

    static Combination* createCombination(QVector<int>);

    QVector<BaseCard*> getCards() const;
    BaseCard* getFirstCard() const;
    BaseCard* getLastCard() const;
    int size() const;


private:
    Combination(QVector<BaseCard*>, Type);
    Type type;
    QVector<BaseCard*> cards;
};

#endif // COMBINATION_H
