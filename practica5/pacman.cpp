#include "pacman.h"
#include <QTimer>
#include <QGraphicsScene>

//Pacman::Pacman(QObject *parent)
//    : QObject{parent}
//{
Pacman::Pacman(QPixmap pixmap)

{
    pacmanTimer_boca = new QTimer();
    pacmanTimer_move = new QTimer();

    setPixmap(pixmap);

  //  pixmap = new QPixmap(":/imagenes/spt1_40.png");

    fila = 0;
    columna = 0;
    ancho = 40;
    alto = 40;
    direccion = 1;
    puntaje = 0;

    //this->setPos(420,660);
    setX(420);
    setY(660);



    pacmanTimer_move->start(200);
    pacmanTimer_boca->start(200);

    connect(pacmanTimer_boca, &QTimer::timeout, this, &Pacman::Actualizacion);
 //   connect(pacmanTimer, &QTimer::timeout, this, &Pacman::movimiento);
    connect(pacmanTimer_move, &QTimer::timeout, this, &Pacman::regla);


}

QRectF Pacman::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, this->pixmap(), columna, direccion*40, ancho, alto);
}

void Pacman::Actualizacion()
{

    //this->setX(pasos);
    columna +=40;
    if(columna>=80){

        columna = 0;

    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}

void Pacman::movimiento(int _direccion)
{
//    static int cont = x();
//    pasos+=(cont+40);
    if(_direccion==0){
        this->setX( x()+40);
    }else if(_direccion==1){
        this->setX( x()-40);
    }else if(_direccion==2){
        this->setY( y()-40);
    }else if(_direccion==3){
        this->setY( y()+40);
    }
//    cont+=40;

}


qreal Pacman::y() const
{
    return m_y;
}

void Pacman::setY(qreal newY)
{
    moveBy(0,newY-m_y);
    m_y = newY;
}

qreal Pacman::x() const
{
    return m_x;
}

void Pacman::setX(qreal newX)
{
    moveBy(newX-m_x,0);

    m_x = newX;
}



void Pacman::regla(){

    int y2 =(x()/40)-1;
    int x2 =((y())/40)-1;

//    if  ((x()/40)>18 or ((y())/40)>20
//         or (x()/40)<0 or ((y())/40)<0){
    if  (y2>18 or x2>20 or y2<0 or x2<0){

        if(y2>=18){
            y2--;
        }

        if(x2>=20){
            x2--;
        }
        qDebug() << "Error number: " << direccion ;
        qDebug()  << "ry2 "<<y2;
        qDebug()  << "rx2 "<<x2;
    }else{
        y2 =(x()/40);
        x2 =((y())/40);
        qDebug() << matriz[y2][x2] ;
        qDebug()  << "";

        if(direccion==0){
            //derecha
            qDebug() << "derecha ";
            if(matriz[y2+1][x2]==0){
                movimiento(direccion);

            }else if(matriz[y2+1][x2]==2){

                qDebug() << y2;

                movimiento(direccion);
                matriz[y2+1][x2]=0;
                puntaje+=10;

            }else if(matriz[y2+1][x2]==3){

                movimiento(direccion);
                //matriz[y2+1][x2]=0;
                puntaje+=50;

            }else{
                qDebug() << "obstaculo ";
            }

        }else if(direccion==1){
            //izquierda
            qDebug() << "izquierda ";
            if(matriz[y2-1][x2]==0){
                movimiento(direccion);

            }else if(matriz[y2-1][x2]==2){

                qDebug() << y2;

                movimiento(direccion);
                puntaje+=10;

            }else if(matriz[y2-1][x2]==3){

                movimiento(direccion);
                puntaje+=50;

            }else{
                qDebug() << "obstaculo ";
            }
        }else if(direccion==2){
            //abajo
            qDebug() << "abajo ";
            if(matriz[y2][x2-1]==0){
                movimiento(direccion);

            }else if(matriz[y2][x2-1]==2){

                qDebug() << y2;

                movimiento(direccion);
                puntaje+=10;

            }else if(matriz[y2][x2-1]==3){

                movimiento(direccion);
                puntaje+=50;

            }else{
                qDebug() << "obstaculo ";
            }
        }else if(direccion==3){
            //arriba
            qDebug() << "arriba ";
            if(matriz[y2][x2+1]==0){
                movimiento(direccion);

            }else if(matriz[y2][x2+1]==2){

                qDebug() << y2;

                movimiento(direccion);
                puntaje+=10;

            }else if(matriz[y2][x2+1]==3){

                movimiento(direccion);
                puntaje+=50;

            }else{
                qDebug() << "obstaculo ";
            }
        }
        //direccion = 1;
        qDebug() << "Regla ";
    }
    qDebug()  << "rr "<< matriz[x()/40][y()/40];
//    y2 =(x()/40);
//    x2 =((y())/40);
    qDebug()  << "ry2, "<<y2;
    qDebug()  << "rx2, "<<x2;

}



