#ifndef MOOB1_H
#define MOOB1_H

#include <QGraphicsPixmapItem>
#include <QMouseEvent>

class moob1 : public QObject, public  QGraphicsPixmapItem
{
public:
    int x ;
    int y ;
    moob1();
    void pintar();


};

#endif // MOOB1_H
