#ifndef VISUALCARD_H
#define VISUALCARD_H
#include <QGraphicsPixmapItem>
#include "../client/basecard.h"


class VisualCard : public QGraphicsPixmapItem
{
public:
    explicit VisualCard(int, QGraphicsItem *parent);
    void setCard(int);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
};

#endif // VISUALCARD_H
