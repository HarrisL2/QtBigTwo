#include "hand.h"
#include "playingcard.h"
#include "unocard.h"

/*
 *  Hand::Hand(var)
 *  @funct: creates a combination from the variable
 *  @param: var
 *  @return: N/A
 */


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
    sort();
}

Hand::Hand(const QJsonArray& ids) {
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i].toInt() < 99) {
            cards.append(new PlayingCard(ids[i].toInt()));
        }
        else {
            cards.append(new UNOCard(ids[i].toInt()));
        }
    }
    sort();
}

/*
 *  Hand::toJsonArray()
 *  @funct: returns hand as a JsonArray
 *  @param: N/A
 *  @return: JsonArray
 */


QJsonArray Hand::toJsonArray() {
    QJsonArray arr;
    for (int i = 0; i < cards.size(); i++) {
        arr.append(cards[i]->getID());
    }
    return arr;
}

/*
 *  Hand::add/removeCard()
 *  @funct: add/removes the corresponding card to the hand
 *  @param: card to add/remove
 *  @return: N/A
 */

void Hand::addCard(BaseCard* card) {
    cards.append(card);
    sort();
}

void Hand::removeCard(int id) {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getID() == id) {
            cards.remove(i);
        }
    }
}

/*
 *  Hand::sort()
 *  @funct: sort the hand of cards from small to large
 *  @param: N/A
 *  @return: N/A
 */

void Hand::sort() {
    for (int i = 0; i < cards.size(); i++){
        for (int j = i; j < cards.size(); j++){
            if (cards[j]->getID() < cards[i]->getID()){
                BaseCard* temp = cards[j];
                cards[j] = cards[i];
                cards[i] = temp;
            }
        }
    }
    for (int i = 0; i < cards.size(); i++){
        for (int j = i; j < cards.size(); j++){
            if ((cards[j]->getNumber() < 3 ?  cards[j]->getNumber() + 13 : cards[j]->getNumber()) <
                    (cards[i]->getNumber() < 3 ?  cards[i]->getNumber() + 13 : cards[i]->getNumber())){
                BaseCard* temp = cards[j];
                cards[j] = cards[i];
                cards[i] = temp;
            }
        }
    }
}

/*
 *  Hand::num<var>(<type>)
 *  @funct: return the number of cards that fit the type
 *  @param: type
 *  @return: int
 */


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

/*
 *  Hand::get<var>()
 *  @funct: return all cards that fit the citeria
 *  @param: type
 *  @return: vector of BaseCard*
 */


QVector<BaseCard*> Hand::getCards() const {
    return cards;
}

QVector<BaseCard*> Hand::getAllNum(int num) const {
    QVector<BaseCard*> out;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getNumber() == num) {
            out.append(cards[i]);
        }
    }
    return out;
}

QVector<BaseCard*> Hand::getAllSuit(BaseCard::Suit suit) const {
    QVector<BaseCard*> out;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getSuit() == suit) {
            out.append(cards[i]);
        }
    }
    return out;
}

QVector<BaseCard*> Hand::getAllColor(BaseCard::Color color) const {
    QVector<BaseCard*> out;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getColor() == color) {
            out.append(cards[i]);
        }
    }
    return out;
}
