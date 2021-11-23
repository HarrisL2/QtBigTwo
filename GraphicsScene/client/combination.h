#ifndef COMBINATION_H
#define COMBINATION_H

#include <QVector>
#include "basecard.h"

class Combination
{
public:
    enum class TYPE {
        SINGLE,
        PAIR,
        TRIPLE,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH
    };

    static Combination* createCombination(QVector<BaseCard*>);

    QVector<BaseCard*> getCards() const;
    int size() const;


private:
    Combination(QVector<BaseCard*>);
    QVector<BaseCard*> cards;
};

#endif // COMBINATION_H
