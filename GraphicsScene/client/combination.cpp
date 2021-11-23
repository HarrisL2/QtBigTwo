#include "combination.h"

Combination* Combination::createCombination(QVector<BaseCard *> cards) {
    if (cards.size() <= 5 && cards.size() >= 1) {
        if (cards.size() == 1) {
            return new Combination(cards);
        }
        if (cards.size() == 2 && cards[0]->getNumber() == cards[1]->getNumber()) {
            return new Combination(cards);
        }
        if (cards.size() == 3 && cards[0]->getNumber() == cards[1]->getNumber() && cards[0]->getNumber() == cards[2]->getNumber()) {
            return new Combination(cards);
        }
        if (cards.size() == 5) {
            //TODO 5 card checking
            return new Combination(cards);
        }
    }
    return nullptr;
}

Combination::Combination(QVector<BaseCard*> cards) :
    cards(cards)
{

}

QVector<BaseCard*> Combination::getCards() const {
    return cards;
}

int Combination::size() const {
    return cards.size();
}
