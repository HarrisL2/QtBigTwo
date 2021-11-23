#ifndef VISUALHAND_H
#define VISUALHAND_H

#include <QGraphicsItem>
#include <QResizeEvent>
#include "visualcard.h"

class VisualHand : public QGraphicsItem
{
public:
    VisualHand(
            int HAND_WIDTH, int HAND_HEIGHT,
            int CARD_WIDTH, int CARD_HEIGHT,
            const QVector<int>& ids);
    void changeHand(const QVector<int>&);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
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
    QVector<VisualCard*> cards;
};

#endif // VISUALHAND_H
