#include "tablegraphics.h"
#include "visualcard.h"
#include "QGraphicsSceneMouseEvent"

#include <QtDebug>

TableGraphics::TableGraphics() :
    QGraphicsScene(),
    WIDTH(1280),
    HEIGHT(720),
    CARD_WIDTH(WIDTH/8.0),
    CARD_HEIGHT(CARD_WIDTH*1.45),
    debugLabel(new QGraphicsTextItem("0,0"))
{
    for (int i = 0; i < 4; i++) {
        hands.append(new VisualHand(WIDTH*0.6, HEIGHT*0.2, CARD_WIDTH, CARD_HEIGHT,
                              QVector<int>(0),i==0));
        this->addItem(hands[i]);
        lastPlays.append(new VisualHand(WIDTH*0.6, HEIGHT*0.2, CARD_WIDTH, CARD_HEIGHT,
                                        QVector<int>(0),false));
        this->addItem(lastPlays[i]);
    }
    this->addItem(debugLabel);
    debugLabel->setPos(0,0);
    this->setSceneRect(0,0,WIDTH-2,HEIGHT-2);
}

void TableGraphics::changeHand(int i, const QJsonArray& ids) {
    hands[i]->changeHand(ids);
}

void TableGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsScene::mousePressEvent(event);
    QVector<int> selected = hands[0]->getSelected();
    for (int i = 0; i < selected.size(); i++) {
        if (!lastPlays[0]->hasCard(selected[i])) {
            lastPlays[0]->addCard(selected[i]);
        }
    }
    QVector<int> pastSelected = lastPlays[0]->getCards();
    for (int i = 0; i < pastSelected.size(); i++) {
        if (!selected.contains(pastSelected[i])) {
            lastPlays[0]->removeCard(pastSelected[i]);
        }
    }
    if (!event->isAccepted()) {
        debugLabel->setPlainText(
                    QString::number(event->scenePos().x())+
                    ", "+
                    QString::number(event->scenePos().y()));
    }
}

QVector<int> TableGraphics::getNextPlay() {
    return lastPlays[0]->getCards();
}

void TableGraphics::resizeEvent(QResizeEvent* event) {
    WIDTH = event->size().width();
    HEIGHT = event->size().height();
    this->setSceneRect(0,0,WIDTH-2,HEIGHT-2);
    CARD_WIDTH = WIDTH/10.0;
    CARD_HEIGHT = CARD_WIDTH*1.45;
    if (WIDTH*0.6 > 600) {
        hands[0]->setPos(WIDTH*0.2,HEIGHT-CARD_HEIGHT*0.6);
        hands[0]->resizeEvent(WIDTH*0.6,HEIGHT*0.2,CARD_WIDTH,CARD_HEIGHT,event);

        hands[2]->setPos(WIDTH*0.2,-CARD_HEIGHT*0.4);
        hands[2]->resizeEvent(WIDTH*0.6,HEIGHT*0.2,CARD_WIDTH,CARD_HEIGHT,event);
    } else {
        hands[0]->setPos((WIDTH-600)/2,HEIGHT-CARD_HEIGHT*0.6);
        hands[0]->resizeEvent(600,HEIGHT*0.2,CARD_WIDTH,CARD_HEIGHT,event);

        hands[2]->setPos((WIDTH-600)/2,-CARD_HEIGHT*0.4);
        hands[2]->resizeEvent(600,HEIGHT*0.2,CARD_WIDTH,CARD_HEIGHT,event);
    }
    hands[1]->setRotation(270);
    hands[1]->setPos(WIDTH-CARD_HEIGHT*0.6,HEIGHT*0.8);
    hands[1]->resizeEvent(HEIGHT*0.6,WIDTH*0.2,CARD_WIDTH,CARD_HEIGHT,event);
    hands[3]->setRotation(90);
    hands[3]->setPos(CARD_HEIGHT*0.6,HEIGHT*0.2);
    hands[3]->resizeEvent(HEIGHT*0.6,WIDTH*0.2,CARD_WIDTH,CARD_HEIGHT,event);

    lastPlays[0]->setPos(WIDTH*0.4,HEIGHT-CARD_HEIGHT*1.2);
    lastPlays[0]->resizeEvent(WIDTH*0.2,HEIGHT*0.2,CARD_WIDTH*0.5,CARD_HEIGHT*0.5,event);

    debugLabel->setPlainText(
                QString::number( event->size().width())+
                ", "+
                QString::number(event->size().height()));
}
