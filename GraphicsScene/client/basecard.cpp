#include "basecard.h"

BaseCard::BaseCard()
{

}

BaseCard::Suit BaseCard::getSuit() const {
    return BaseCard::Suit::NOSUIT;
}

BaseCard::Color BaseCard::getColor() const {
    return BaseCard::Color::NOCOLOR;
}

BaseCard::Effect BaseCard::getEffect() const {
    return BaseCard::Effect::NOEFFECT;
}
