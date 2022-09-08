#include "rectangulo.h"

Rectangulo::Rectangulo():
    topPillar(new QGraphicsPixmapItem(QPixmap(":imagenes/rectangulo.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":imagenes/rectangulo.png")))
{

    addToGroup(topPillar);
    addToGroup(bottomPillar);
}
