#include "pared.h"

Pared::Pared(int est,float alt,float anc, float _x, float _y)
{
estado = est;
altura = alt;
ancho = anc;
x = _x;
y = _y;
}

QRectF Pared::boundingRect() const{
//return QRectF(x,y,radio,2*radio);
    return QRectF(x,y,altura,ancho);
}

void Pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
       QWidget *widget){
if(estado==1){
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}else if(estado==2){
  //  painter->setBrush(Qt::black);
   // painter->drawRect(boundingRect());
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect().x()+15,boundingRect().y()+15,boundingRect().width()-30,boundingRect().height()-30);
}else{
    //painter->setBrush(Qt::white);
}
//painter->drawEllipse(boundingRect());

}

int Pared::contacto(Pacman *pac)
{
    int val;
    //qDebug() << x<<" , ";
    if(x>=pac->x()+40){
        val=1;
}else{
        val=0;
    }

    return val;
}

int Pared::getEstado() const
{
    return estado;
}

void Pared::setEstado(int newEstado)
{
    estado = newEstado;
}

