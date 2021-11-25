#include "visualcard.h"

#include "QGraphicsSceneMouseEvent"

VisualCard::VisualCard(int id, bool clickable, QGraphicsItem *parent = nullptr) :
    QGraphicsPixmapItem(parent),
    id(id),
    clickable(clickable),
    selected(false)
{
    QPixmap texture(":/cards/png/"+QString::number(id)+".png");
    this->setPixmap(texture);
}

int VisualCard::getID() const {
    return id;
}

bool VisualCard::isSelected() const {
    return selected;
}

void VisualCard::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        if (clickable) {
            event->accept();
            if (!selected) {
                setY(y()-20);
                selected = true;
            } else {
                setY(y()+20);
                selected = false;
            }
        }
    }
}
