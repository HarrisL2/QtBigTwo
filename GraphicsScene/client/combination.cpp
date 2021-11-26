#include "combination.h"
#include "playingcard.h"
#include "unocard.h"

Combination* Combination::createCombination(QVector<int> ids) {
    QVector<BaseCard*> cards;
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i] < 99) {
            cards.append(new PlayingCard(ids[i]));
        } else {
            cards.append(new UNOCard(ids[i]));
        }
    }
    if (cards.size() == 0) {
        return new Combination(cards, Combination::Type::PASS);
    }
    if (cards.size() <= 5 && cards.size() >= 1) {
        if (cards.size() == 1) {
            return new Combination(cards, Combination::Type::SINGLE);
        }
        if (cards.size() == 2 && cards[0]->getNumber() == cards[1]->getNumber()) {
            return new Combination(cards, Combination::Type::PAIR);
        }
        if (cards.size() == 3 && cards[0]->getNumber() == cards[1]->getNumber() && cards[0]->getNumber() == cards[2]->getNumber()) {
            return new Combination(cards, Combination::Type::TRIPLE);
        }
        if (cards.size() == 5) {
            //TODO 5 card checking
            return new Combination(cards, Combination::Type::STRAIGHT_FLUSH);
        }
    }
    return nullptr;
}

Combination::Combination(QVector<BaseCard*> cards, Type type) :
    type(type),
    cards(cards)
{

}

QVector<BaseCard*> Combination::getCards() const {
    return cards;
}

BaseCard* Combination::getFirstCard() const {
    return cards.first();
}

BaseCard* Combination::getLastCard() const {
    return cards.back();
}

int Combination::size() const {
    return cards.size();
}
