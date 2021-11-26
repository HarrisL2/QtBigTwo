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

Combination::Type Combination::getType() const {
    return type;
}

int Combination::size() const {
    return cards.size();
}
