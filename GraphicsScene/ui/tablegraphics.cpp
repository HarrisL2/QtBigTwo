#include "tablegraphics.h"
#include "visualcard.h"
#include "QGraphicsSceneMouseEvent"
#include <QtDebug>

TableGraphics::TableGraphics() :
    QGraphicsScene(),
    WIDTH(1280),
    HEIGHT(720),
    CARD_WIDTH(WIDTH/6),
    CARD_HEIGHT(HEIGHT*1.45),
    debugLabel(new QGraphicsTextItem("0,0"))
{
    badCardCount = 3;
    QVector<int> cardIDs(3);
    for (int i = 0; i < cardIDs.size(); i++) {
        cardIDs[i] = i+1;
    }
    qDebug() << cardIDs;
    demoHand = new VisualHand(WIDTH*0.6, HEIGHT*0.2, CARD_WIDTH, CARD_HEIGHT,
                              cardIDs);
    this->addItem(demoHand);
    demoHand->setPos(WIDTH*0.2,HEIGHT*0.8);
    this->addItem(debugLabel);
    debugLabel->setPos(0,0);
    this->setSceneRect(0,0,WIDTH-2,HEIGHT-2);

}

void TableGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsScene::mousePressEvent(event);

    if (!event->isAccepted()) {
        if (event->button() == Qt::MouseButton::LeftButton) {
            badCardCount++;
            QVector<int> cardIDs(badCardCount);
            for (int i = 0; i < cardIDs.size(); i++) {
                cardIDs[i] = i+1;
            }
            demoHand->changeHand(cardIDs);
        } else if (event->button() == Qt::MouseButton::RightButton) {
            badCardCount--;
            QVector<int> cardIDs(badCardCount);
            for (int i = 0; i < cardIDs.size(); i++) {
                cardIDs[i] = i+1;
            }
            demoHand->changeHand(cardIDs);
        }

        debugLabel->setPlainText(
                    QString::number(event->scenePos().x())+
                    ", "+
                    QString::number(event->scenePos().y()));
    }
}

void TableGraphics::resizeEvent(QResizeEvent* event) {
    WIDTH = event->size().width();
    HEIGHT = event->size().height();
    this->setSceneRect(0,0,WIDTH-2,HEIGHT-2);
    CARD_WIDTH = WIDTH/6;
    CARD_HEIGHT = HEIGHT*1.45;
    if (WIDTH*0.6 > 600) {
        demoHand->setPos(WIDTH*0.2,HEIGHT*0.8);
        demoHand->resizeEvent(WIDTH*0.6,HEIGHT*0.2,CARD_WIDTH,CARD_HEIGHT,event);
    } else {
        demoHand->setPos((WIDTH-600)/2,HEIGHT*0.8);
        demoHand->resizeEvent(600,HEIGHT*0.2,CARD_WIDTH,CARD_HEIGHT,event);
    }
    debugLabel->setPlainText(
                QString::number( event->size().width())+
                ", "+
                QString::number(event->size().height()));
}
