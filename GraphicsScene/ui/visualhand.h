#ifndef VISUALHAND_H
#define VISUALHAND_H

#include <QGraphicsItem>
#include <QResizeEvent>

#include <QJsonArray>

#include "visualcard.h"

/*
 * VisualHand is a QGraphicItem that contains a variable amount
 * of VisualCards that will dynamically resize to fit within
 * it's boundaries.
 */

class VisualHand : public QGraphicsItem
{

public:
    VisualHand(
            int HAND_WIDTH, int HAND_HEIGHT,
            int CARD_WIDTH, int CARD_HEIGHT,
            const QVector<int>& ids, bool clickable);
    void changeHand(const QJsonArray&);
    void addCard(int);
    void removeCard(int);
    bool hasCard(int);
    QVector<int> getSelected();
    QVector<int> getCards();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void resizeEvent(
            int HAND_WIDTH, int HAND_HEIGHT,
            int CARD_WIDTH, int CARD_HEIGHT,
            QResizeEvent* event);
    void renderHand();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QRectF boundingRect() const;


private:
    int WIDTH, HEIGHT;
    int CARD_WIDTH, CARD_HEIGHT;
    bool clickable;
    QVector<VisualCard*> cards;
};

#endif // VISUALHAND_H
