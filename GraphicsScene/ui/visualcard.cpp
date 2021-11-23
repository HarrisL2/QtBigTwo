#include "visualcard.h"

#include "QGraphicsSceneMouseEvent"

VisualCard::VisualCard(int id, QGraphicsItem *parent = nullptr) :
    QGraphicsPixmapItem(parent)
{
    QPixmap texture(":/cards/png/"+QString::number(id)+".png");
    this->setPixmap(texture);
}

void VisualCard::setCard(int id) {
    QPixmap texture(":/cards/png/"+QString::number(id)+".png");
    this->setPixmap(texture);
}


void VisualCard::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        event->accept();
    }
}
