#ifndef TABLEGRAPHICS_H
#define TABLEGRAPHICS_H
#include <QGraphicsScene>
#include <QResizeEvent>

#include "visualhand.h"
#include "../client/playingcard.h"

class TableGraphics : public QGraphicsScene
{
public:
    TableGraphics();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void resizeEvent(QResizeEvent* event);
private:
    int WIDTH, HEIGHT;
    int CARD_WIDTH, CARD_HEIGHT;

    int badCardCount;
    VisualHand* demoHand;
    QGraphicsTextItem* debugLabel;

};

#endif // TABLEGRAPHICS_H
