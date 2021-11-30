#ifndef TABLEGRAPHICS_H
#define TABLEGRAPHICS_H
#include <QGraphicsScene>
#include <QResizeEvent>
#include <QVector>

#include "visualhand.h"
#include "../client/playingcard.h"

/*
 * TableGraphics is a QGraphicsScene with detailed
 * UI elements for the use of a 2-4 player card-based
 * game. It has turn direction indicators and also spaces
 * for previous plays. It is also able to take mouse
 * inputs and translate them to selected cards.
 */

class TableGraphics : public QGraphicsScene
{

public:
    TableGraphics();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void resizeEvent(QResizeEvent* event);

    void changeHand(int, const QJsonArray&);
    void setName(int, QString);
    void setCount(int, QString);
    void setLastPlay(int i, const QJsonArray& ids);
    void setCurrent(int i);
    void setDirection(int i);
    QVector<int> getNextPlay();


private:
    int WIDTH, HEIGHT;
    int CARD_WIDTH, CARD_HEIGHT;

    QVector<VisualHand*> hands;
    QVector<VisualHand*> lastPlays;
    QVector<QGraphicsTextItem*> nameLabels;
    QVector<QGraphicsTextItem*> countLabels;
    QVector<QGraphicsRectItem*> indicators;
    QVector<QGraphicsPixmapItem*> arrows;
    QGraphicsTextItem* debugLabel;

};

#endif // TABLEGRAPHICS_H
