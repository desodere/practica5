#include "moob1.h"

moob1::moob1()
{
    x = 40;
    y = 40;
    //pintar();
}


void moob1::pintar(){
    setPixmap(QPixmap(":/imagenes/imagenes.png"));
}

