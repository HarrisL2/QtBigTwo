#include "hand.h"
#include "playingcard.h"
#include "unocard.h"

Hand::Hand(const QVector<BaseCard*>& cards)
{
    this->cards = cards;
}

Hand::Hand(const QVector<int>& ids) : cards(QVector<BaseCard*>(0)) {
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i] < 99) {
            cards.append(new PlayingCard(ids[i]));
        }
        else {
            cards.append(new UNOCard(ids[i]));
        }
    }
}

void Hand::addCard(BaseCard* card) {
    cards.append(card);
}

void Hand::removeCard(BaseCard* card) {
    cards.removeOne(card);
}

int Hand::numCards() const {
    return cards.size();
}

int Hand::numType(BaseCard::Type type) const {
    int num = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getType() == type) {
            num++;
        }
    }
    return num;
}

int Hand::numSuit(BaseCard::Suit suit) const {
    int num = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getSuit() == suit) {
            num++;
        }
    }
    return num;
}

int Hand::numColor(BaseCard::Color color) const {
    int num = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getColor() == color) {
            num++;
        }
    }
    return num;
}

int Hand::numNum(int number) const {
    int num = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getNumber() == number) {
            num++;
        }
    }
    return num;
}

QVector<BaseCard*> Hand::getCards() const {
    return cards;
}
