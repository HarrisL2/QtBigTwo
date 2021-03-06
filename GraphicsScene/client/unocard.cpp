#include "unocard.h"

/*
 *  PlayingCards::PlayingCard(int id)
 *  @funct: create a UNO card from given id
 *  @param: N/A
 *  @return: N/A
 */

UNOCard::UNOCard(int id) :
    ID(id),
    number((id-101)/4 + 3 > 13 ? (id-101)/4 - 10: (id-101)/4 + 3), \
    color(static_cast<BaseCard::Color>( (id-100)%4 == 0? 4 : (id-100)%4 ))
{

}

/*
 *  UNOCard::get<var>()
 *  @funct: return the required variable
 *  @param: N/A
 *  @return: var
 */

BaseCard::Type UNOCard::getType() const {
    return BaseCard::Type::UNO;
}

BaseCard::Color UNOCard::getColor() const {
    return color;
}

BaseCard::Effect UNOCard::getEffect() const {
    switch (number) {
        case 11:
            return BaseCard::Effect::REVERSE;
        case 12:
            return BaseCard::Effect::SKIP;
        case 13:
            return BaseCard::Effect::DRAWTWO;
        default:
            return BaseCard::Effect::NOEFFECT;
    }
}

int UNOCard::getNumber() const {
    return number;
}

int UNOCard::getID() const {
    return ID;
}
