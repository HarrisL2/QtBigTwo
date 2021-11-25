#ifndef VISUALCARD_H
#define VISUALCARD_H
#include <QGraphicsPixmapItem>
#include "../client/basecard.h"


class VisualCard : public QGraphicsPixmapItem
{

public:
    explicit VisualCard(int, bool clickable, QGraphicsItem *parent);
    int getID() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    bool isSelected() const;

private:
    int id;
    bool clickable;
    bool selected;
};

#endif // VISUALCARD_H
