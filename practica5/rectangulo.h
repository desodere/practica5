#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

class Rectangulo : public QObject, public  QGraphicsItemGroup
{

        Q_OBJECT
public:
    explicit Rectangulo();
    //Rectangulo();

signals:

public slots:

private:
    QGraphicsPixmapItem * topPillar;
    QGraphicsPixmapItem * bottomPillar;
};

#endif // RECTANGULO_H
