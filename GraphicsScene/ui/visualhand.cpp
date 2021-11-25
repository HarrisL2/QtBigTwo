#include "visualhand.h"
#include <QtDebug>

VisualHand::VisualHand(int HAND_WIDTH, int HAND_HEIGHT,
        int CARD_WIDTH, int CARD_HEIGHT,
        const QVector<int> &ids, bool clickable) :
    WIDTH(HAND_WIDTH), HEIGHT(HAND_HEIGHT),
    CARD_WIDTH(CARD_WIDTH), CARD_HEIGHT(CARD_HEIGHT),
    clickable(clickable)
{
    for(int i = 0; i < ids.size(); i++) {
        cards.append(new VisualCard(ids[i], clickable, this));
    }
    renderHand();
}

void VisualHand::changeHand(const QJsonArray &ids) {
    for(int i = 0; i < cards.size(); i++) {
        delete cards[i];
    }
    cards.clear();
    for(int i = 0; i < ids.size(); i++) {
        cards.append(new VisualCard(ids[i].toInt(), clickable, this));
    }
    renderHand();
}

void VisualHand::addCard(int id) {
    cards.append(new VisualCard(id, clickable, this));
    renderHand();
}

void VisualHand::removeCard(int id) {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getID() == id) {
            cards[i]->hide();
            delete cards[i];
            cards.removeAt(i);
        }
    }
    renderHand();
}

bool VisualHand::hasCard(int id) {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->getID() == id) {
            return true;
        }
    }
    return false;
}

QVector<int> VisualHand::getSelected() {
    QVector<int> nums;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i]->isSelected()) {
            nums.append(cards[i]->getID());
        }
    }
    return nums;
}

QVector<int> VisualHand::getCards() {
    QVector<int> nums;
    for (int i = 0; i < cards.size(); i++) {
        nums.append(cards[i]->getID());
    }
    return nums;
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
        double cardDistance = (WIDTH-CARD_WIDTH)/(cards.size()-1);
        for(int i = 0; i < cards.size(); i++) {
            cards[i]->setScale(CARD_WIDTH/500.0);
            cards[i]->setPos(cardDistance*i,0);
        }
    }
}

void VisualHand::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);
    qDebug() << "cliked";
}

void VisualHand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}
QRectF VisualHand::boundingRect() const {
    return QRectF(this->x(),this->y(),WIDTH,HEIGHT);
}
