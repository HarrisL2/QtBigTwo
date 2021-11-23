#include "visualhand.h"

VisualHand::VisualHand(int HAND_WIDTH, int HAND_HEIGHT,
        int CARD_WIDTH, int CARD_HEIGHT,
        const QVector<int> &ids) :
    WIDTH(HAND_WIDTH), HEIGHT(HAND_HEIGHT),
    CARD_WIDTH(CARD_WIDTH), CARD_HEIGHT(CARD_HEIGHT)
{
    for(int i = 0; i < ids.size(); i++) {
        cards.append(new VisualCard(ids[i],this));
    }
    renderHand();
}

void VisualHand::changeHand(const QVector<int> &ids) {
    for(int i = 0; i < cards.size(); i++) {
        delete cards[i];
    }
    cards.clear();
    for(int i = 0; i < ids.size(); i++) {
        cards.append(new VisualCard(ids[i],this));
    }
    renderHand();
}
void VisualHand::resizeEvent(
        int HAND_WIDTH, int HAND_HEIGHT,
        int CARD_WIDTH, int CARD_HEIGHT,
        QResizeEvent *event) {
    this->CARD_WIDTH = CARD_WIDTH;
    this->CARD_HEIGHT = CARD_HEIGHT;
    this->WIDTH = HAND_WIDTH;
    this->HEIGHT = HAND_HEIGHT;
    renderHand();
}

void VisualHand::renderHand() {
    int totalCardWidth = CARD_WIDTH * cards.size();
    if (totalCardWidth < WIDTH) {
        int startpoint = (WIDTH - totalCardWidth)/2;
        for(int i = 0; i < cards.size(); i++) {
            cards[i]->setScale(CARD_WIDTH/500.0);
            cards[i]->setPos(startpoint+CARD_WIDTH*i,0);
        }
    } else {
        int cardDistance = (WIDTH-CARD_WIDTH)/(cards.size()-1);
        for(int i = 0; i < cards.size(); i++) {
            cards[i]->setScale(CARD_WIDTH/500.0);
            cards[i]->setPos(cardDistance*i,0);
        }
    }
}

void VisualHand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}
QRectF VisualHand::boundingRect() const {
    return QRectF(this->x(),this->y(),WIDTH,HEIGHT);
}
