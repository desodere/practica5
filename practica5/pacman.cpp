#include "pacman.h"
#include <QTimer>
#include <QGraphicsScene>

Pacman::Pacman(QPixmap pixmap):
    posicion(Posicion::derecha),
    direccion(1)
{
    setPixmap(pixmap);

    QTimer * pacmanTimer = new QTimer(this);
    connect(pacmanTimer,&QTimer::timeout,[=](){
        actualizarPixmap();
    });

    pacmanTimer->start(80);

//    y_ubicacion = scenePos().y()+40;
    y_ubicacion = scenePos().y()+640;

    yanimacion =new QPropertyAnimation(this,"y",this);
    yanimacion->setStartValue(scenePos().y());
    yanimacion->setEndValue(y_ubicacion);
    //yanimacion->setEasingCurve(QEasingCurve::Linear);
    yanimacion->setDuration(1);

    yanimacion->start();

//    x_ubicacion = scenePos().x()+40;
    x_ubicacion = scenePos().x()+400;
    xanimacion =new QPropertyAnimation(this,"x",this);
    xanimacion->setStartValue(scenePos().x());
    xanimacion->setEndValue(x_ubicacion);
    //yanimacion->setEasingCurve(QEasingCurve::Linear);
    xanimacion->setDuration(1);

    xanimacion->start();


    yrotacion = new QPropertyAnimation(this,"rotacion",this);

    //rotateTo(90,1200,QEasingCurve::Linear);

}

void Pacman::actualizarPixmap()
{

    if(direccion==1){
        setPixmap(QPixmap(":/imagenes/pac.png"));
        posicion = Posicion::derecha;
        direccion = 1;
    }else if(direccion==2){
        setPixmap(QPixmap(":/imagenes/pac.png"));
        posicion = Posicion::abajo;
        direccion = 2;
    }else if(direccion==3){
        setPixmap(QPixmap(":/imagenes/pac.png"));
        posicion = Posicion::izquierda;
        direccion = 3;
    }else if(direccion==4){
        setPixmap(QPixmap(":/imagenes/pac.png"));
        posicion = Posicion::arriba;
        direccion = 4;
    }else{
        setPixmap(QPixmap(":/imagenes/arriba.png"));
        posicion = Posicion::derecha;
        direccion = 1;
    }
}

qreal Pacman::rotacion() const
{
    return m_rotacion;
}

void Pacman::setRotacion(qreal newRotacion)
{
    m_rotacion = newRotacion;

    QPointF c = boundingRect().center();

    QTransform t;
    t.translate(c.x(),c.y());
    t.rotate(newRotacion);
    t.translate(-c.x(),-c.y());
    setTransform(t);
}


void Pacman::ir_arriba()
{
    yanimacion->stop();
    yrotacion->stop();

    qreal curPosY = y();
    yanimacion->setStartValue(curPosY);
    yanimacion->setEndValue(curPosY - 40);
    setY(curPosY - 40);
    yanimacion->setDuration(1);
    yanimacion->start();

    yrotacion->start();
    rotateTo(-90,0,QEasingCurve::Linear);

}

void Pacman::ir_abajo()
{
    yanimacion->stop();
    yrotacion->stop();

    qreal curPosY = y();
    yanimacion->setStartValue(curPosY);
    yanimacion->setEndValue(curPosY + 40);
    setY(curPosY + 40);
    yanimacion->setDuration(1);
    yanimacion->start();

    yrotacion->start();
    rotateTo(90,0,QEasingCurve::Linear);

}

void Pacman::ir_derecha()
{
    xanimacion->stop();
    yrotacion->stop();

    qreal curPosX = x();
    xanimacion->setStartValue(curPosX);
    xanimacion->setEndValue(curPosX + 40);
    setX(curPosX + 40);
    xanimacion->setDuration(1);
    xanimacion->start();

    yrotacion->start();
    rotateTo(0,0,QEasingCurve::Linear);
}

void Pacman::ir_izquierda()
{
    xanimacion->stop();
    yrotacion->stop();

    qreal curPosX = x();
    xanimacion->setStartValue(curPosX);
    xanimacion->setEndValue(curPosX - 40);
    setX(curPosX - 40);
   // yanimacion->setEasingCurve(QEasingCurve::Linear);
    xanimacion->setDuration(1);
    xanimacion->start();

    yrotacion->start();
    rotateTo(-180,0,QEasingCurve::Linear);
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

void Pacman::rotateTo(const qreal &end, const int &duracion, const QEasingCurve &curve)
{
    yrotacion->setStartValue(rotacion());
    yrotacion->setEndValue(end);
   // yrotacion->setEasingCurve(curve);
    yrotacion->setDuration(duracion);

    yrotacion->start();
}


