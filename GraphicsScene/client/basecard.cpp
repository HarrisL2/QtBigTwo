#include "basecard.h"
#include <QtDebug>

BaseCard::BaseCard()
{

}

/*
 *  BaseCard::Suit BaseCard::get<var>()
 *  @funct: return default value for Suit, Color and Effect for each card
 *  @param: N/A
 *  @return: default value for Suit, Color and Effect
 */

BaseCard::Suit BaseCard::getSuit() const {
    return BaseCard::Suit::NOSUIT;
}

BaseCard::Color BaseCard::getColor() const {
    return BaseCard::Color::NOCOLOR;
}

BaseCard::Effect BaseCard::getEffect() const {
    return BaseCard::Effect::NOEFFECT;
}

/*
 *  operator>(const BaseCard& lhs, const BaseCard& rhs)
 *  @funct: returns true if lhs can be played after rhs
 *  @param: lhs card and rhs card
 *  @return: truth value
 */

bool operator>(const BaseCard& lhs, const BaseCard& rhs) {
    int lhsNum = lhs.getNumber(), rhsNum = rhs.getNumber();
    if ((lhsNum <= 2 ? lhsNum + 13 : lhsNum ) > (rhsNum <= 2 ? rhsNum + 13 : rhsNum)) {
        return true;
    } else if (lhsNum == rhsNum) {
        if (lhs.getType() == BaseCard::Type::PLAYING) {
            if (rhs.getType() == BaseCard::Type::PLAYING) {
                return lhs.getSuit() > rhs.getSuit();
            } else {
                return true;
            }
        } else {
            return true;
        }
    }
    return false;
}
