#ifndef TABLEGRAPHICS_H
#define TABLEGRAPHICS_H
#include <QGraphicsScene>
#include <QResizeEvent>
#include <QVector>

#include "visualhand.h"
#include "../client/playingcard.h"

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
    QVector<int> getNextPlay();


private:
    int WIDTH, HEIGHT;
    int CARD_WIDTH, CARD_HEIGHT;

    QVector<VisualHand*> hands;
    QVector<VisualHand*> lastPlays;
    QVector<QGraphicsTextItem*> nameLabels;
    QVector<QGraphicsTextItem*> countLabels;
    QVector<QGraphicsRectItem*> indicators;
    QGraphicsTextItem* debugLabel;

};

#endif // TABLEGRAPHICS_H
