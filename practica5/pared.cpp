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
    painter->setBrush(Qt::transparent);
    painter->drawRect(boundingRect());
}else if(estado==2){
  //  painter->setBrush(Qt::black);
   // painter->drawRect(boundingRect());
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect().x()+15,boundingRect().y()+15,boundingRect().width()-30,boundingRect().height()-30);
}else if(estado==3){

      painter->setBrush(Qt::white);
      painter->drawEllipse(boundingRect().x()+10,boundingRect().y()+10,boundingRect().width()-20,boundingRect().height()-20);
  }else{
    //painter->setBrush(Qt::white);
}
}



int Pared::getEstado() const
{
    return estado;
}

void Pared::setEstado(int newEstado)
{
    estado = newEstado;
}

