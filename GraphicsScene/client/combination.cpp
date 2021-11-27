#include <QtDebug>

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
            QVector<BaseCard*> tempCards(cards);
            for (int i = 0; i < 5; i++){
                for (int j = i; j < 5; j++){
                    if (tempCards[j]->getNumber() < tempCards[i]->getNumber()){
                        BaseCard* temp = tempCards[j];
                        tempCards[j] = tempCards[i];
                        tempCards[i] = temp;
                    }
                }
            }


            if ((tempCards[0]->getNumber() + 1) == tempCards[1]->getNumber() && (tempCards[1]->getNumber() + 1) == tempCards[2]->getNumber() && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                return new Combination(cards, Combination::Type::STRAIGHT);
            }

            if (tempCards[0]->getNumber() == 1 && tempCards[1]->getNumber() == 10 && (tempCards[1]->getNumber() + 1) == tempCards[2]->getNumber() && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                return new Combination(cards, Combination::Type::STRAIGHT);
            }

            if (tempCards[0]->getNumber() == 1 && tempCards[1]->getNumber() == 2 && tempCards[2]->getNumber() == 11 && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                return new Combination(cards, Combination::Type::STRAIGHT);
            }

            if (tempCards[0]->getType() == BaseCard::Type::PLAYING){
                if (tempCards[0]->getSuit() == tempCards[1]->getSuit() && tempCards[0]->getSuit() == tempCards[2]->getSuit() && tempCards[0]->getSuit() == tempCards[3]->getSuit() && tempCards[0]->getSuit() == tempCards[4]->getSuit()){
                    return new Combination(cards, Combination::Type::FLUSH);
                }

                if ((tempCards[0]->getNumber() + 1) == tempCards[1]->getNumber() && (tempCards[1]->getNumber() + 1) == tempCards[2]->getNumber() && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                    if (tempCards[0]->getSuit() == tempCards[1]->getSuit() && tempCards[0]->getSuit() == tempCards[2]->getSuit() && tempCards[0]->getSuit() == tempCards[3]->getSuit() && tempCards[0]->getSuit() == tempCards[4]->getSuit()){
                        return new Combination(cards, Combination::Type::STRAIGHT_FLUSH);
                    }
                }

                if (tempCards[0]->getNumber() == 1 && tempCards[1]->getNumber() == 10 && (tempCards[1]->getNumber() + 1) == tempCards[2]->getNumber() && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                    if (tempCards[0]->getSuit() == tempCards[1]->getSuit() && tempCards[0]->getSuit() == tempCards[2]->getSuit() && tempCards[0]->getSuit() == tempCards[3]->getSuit() && tempCards[0]->getSuit() == tempCards[4]->getSuit()){
                        return new Combination(cards, Combination::Type::STRAIGHT_FLUSH);
                    }
                }

                if (tempCards[0]->getNumber() == 1 && tempCards[1]->getNumber() == 2 && tempCards[2]->getNumber() == 11 && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                    if (tempCards[0]->getSuit() == tempCards[1]->getSuit() && tempCards[0]->getSuit() == tempCards[2]->getSuit() && tempCards[0]->getSuit() == tempCards[3]->getSuit() && tempCards[0]->getSuit() == tempCards[4]->getSuit()){
                        return new Combination(cards, Combination::Type::STRAIGHT_FLUSH);
                    }
                }
            }

            if (tempCards[0]->getType() == BaseCard::Type::UNO){
                if (tempCards[0]->getColor() == tempCards[1]->getColor() && tempCards[0]->getColor() == tempCards[2]->getColor() && tempCards[0]->getColor() == tempCards[3]->getColor() && tempCards[0]->getColor() == tempCards[4]->getColor()){
                    return new Combination(cards, Combination::Type::FLUSH);
                }

                if ((tempCards[0]->getNumber() + 1) == tempCards[1]->getNumber() && (tempCards[1]->getNumber() + 1) == tempCards[2]->getNumber() && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                    if (tempCards[0]->getColor() == tempCards[1]->getColor() && tempCards[0]->getColor() == tempCards[2]->getColor() && tempCards[0]->getColor() == tempCards[3]->getColor() && tempCards[0]->getColor() == tempCards[4]->getColor()){
                        return new Combination(cards, Combination::Type::STRAIGHT_FLUSH);
                    }
                }

                if (tempCards[0]->getNumber() == 1 && tempCards[1]->getNumber() == 10 && (tempCards[1]->getNumber() + 1) == tempCards[2]->getNumber() && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                    if (tempCards[0]->getColor() == tempCards[1]->getColor() && tempCards[0]->getColor() == tempCards[2]->getColor() && tempCards[0]->getColor() == tempCards[3]->getColor() && tempCards[0]->getColor() == tempCards[4]->getColor()){
                        return new Combination(cards, Combination::Type::STRAIGHT_FLUSH);
                    }
                }

                if (tempCards[0]->getNumber() == 1 && tempCards[1]->getNumber() == 2 && tempCards[2]->getNumber() == 11 && (tempCards[2]->getNumber() + 1) == tempCards[3]->getNumber() && (tempCards[3]->getNumber() + 1) == tempCards[4]->getNumber()){
                    if (tempCards[0]->getColor() == tempCards[1]->getColor() && tempCards[0]->getColor() == tempCards[2]->getColor() && tempCards[0]->getColor() == tempCards[3]->getColor() && tempCards[0]->getColor() == tempCards[4]->getColor()){
                        return new Combination(cards, Combination::Type::STRAIGHT_FLUSH);
                    }
                }
            }

            if (tempCards[0]->getNumber() == tempCards[1]->getNumber() && tempCards[0]->getNumber() == tempCards[2]->getNumber() && tempCards[3]->getNumber() == tempCards[4]->getNumber()){
                return new Combination(cards, Combination::Type::FULL_HOUSE);
            }

            if (tempCards[0]->getNumber() == tempCards[1]->getNumber() && tempCards[2]->getNumber() == tempCards[3]->getNumber() && tempCards[2]->getNumber() == tempCards[4]->getNumber()){
                return new Combination(cards, Combination::Type::FULL_HOUSE);
            }

            if (tempCards[0]->getNumber() == tempCards[1]->getNumber() && tempCards[0]->getNumber() == tempCards[2]->getNumber() && tempCards[0]->getNumber() == tempCards[3]->getNumber()){
                return new Combination(cards, Combination::Type::FOUR_OF_A_KIND);
            }

            if (tempCards[1]->getNumber() == tempCards[2]->getNumber() && tempCards[1]->getNumber() == tempCards[3]->getNumber() && tempCards[1]->getNumber() == tempCards[4]->getNumber()){
                return new Combination(cards, Combination::Type::FOUR_OF_A_KIND);
            }

            return nullptr;
        }
    }
    return nullptr;
}

Combination::Combination(QVector<BaseCard*> cards, Type type) :
    type(type),
    cards(cards),
    sorted(cards)
{
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = i; j < sorted.size(); j++) {
            if (sorted[j]->getID() > sorted[i]->getID()) {
                BaseCard* temp = sorted[j];
                sorted[j] = sorted[i];
                sorted[i] = temp;
            }
        }
    }
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = i; j < sorted.size(); j++) {
            if ((sorted[j]->getNumber() < 3 ? sorted[j]->getNumber() + 13 : sorted[j]->getNumber()) >
                    (sorted[i]->getNumber() < 3 ? sorted[i]->getNumber() + 13 : sorted[i]->getNumber())) {
                BaseCard* temp = sorted[j];
                sorted[j] = sorted[i];
                sorted[i] = temp;
            }
        }
    }
}

QVector<BaseCard*> Combination::getCards() const {
    return cards;
}

QVector<BaseCard*> Combination::getSorted() const {
    return sorted;
}

BaseCard* Combination::getFirstCard() const {
    return cards.first();
}

BaseCard* Combination::getLastCard() const {
    return cards.back();
}

Combination::Type Combination::getType() const {
    return type;
}

int Combination::size() const {
    return cards.size();
}

bool operator>(const Combination& lhs, const Combination& rhs) {
    if (lhs.getType() != rhs.getType()) {
        if ((static_cast<int>(lhs.getType()) < 4) || (static_cast<int>(rhs.getType()) < 4)) {
            return false;
        } else {
            return (static_cast<int>(lhs.getType())) > (static_cast<int>(rhs.getType()));
        }
    } else {
        switch (lhs.getType()) {
        BaseCard *lhsMajor, *rhsMajor;
        case Combination::Type::SINGLE:
        case Combination::Type::PAIR:
        case Combination::Type::TRIPLE:
        case Combination::Type::STRAIGHT:
        case Combination::Type::FLUSH:
        case Combination::Type::STRAIGHT_FLUSH:
            return *(lhs.getSorted().at(0)) > *(rhs.getSorted().at(0));
        case Combination::Type::FULL_HOUSE:
            lhsMajor = (lhs.getSorted().at(1)->getNumber()==lhs.getSorted().at(2)->getNumber())?lhs.getSorted().at(0):lhs.getSorted().at(2);
            rhsMajor = (rhs.getSorted().at(1)->getNumber()==rhs.getSorted().at(2)->getNumber())?rhs.getSorted().at(0):rhs.getSorted().at(2);
            return *(lhsMajor) > *(rhsMajor);
        case Combination::Type::FOUR_OF_A_KIND:
            lhsMajor = (lhs.getSorted().at(0)->getNumber()==lhs.getSorted().at(1)->getNumber())?lhs.getSorted().at(0):lhs.getSorted().at(4);
            rhsMajor = (rhs.getSorted().at(0)->getNumber()==rhs.getSorted().at(1)->getNumber())?rhs.getSorted().at(0):rhs.getSorted().at(4);
            return *(lhsMajor) > *(rhsMajor);
        case Combination::Type::PASS:
            return false;
        }
    }
    return false;
}
