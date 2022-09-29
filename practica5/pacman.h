#ifndef PACMAN_H
#define PACMAN_H

#include <vector>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QDebug>
#include "pared.h"

using namespace std;

class Pacman : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
 //   Q_PROPERTY(qreal rotacion READ rotacion WRITE setRotacion)
    Q_PROPERTY(qreal y READ y WRITE setY)
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit Pacman(QPixmap pixmap);
 //   explicit Pacman(QObject *parent = nullptr);

    QTimer *pacmanTimer_boca;
    QTimer *pacmanTimer_move;
   // QPixmap *pixmap;
    float fila, columna;
    float ancho, alto;
    int direccion;
    int puntaje;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    vector<vector<int>> matriz
        {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
        {1,2,2,3,2,2,2,1,0,1,2,1,0,1,2,2,3,1,2,2,2,1},
        {1,2,1,1,2,1,2,1,0,1,2,1,0,1,2,1,2,2,2,1,2,1},
        {1,2,1,1,2,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,2,1},
        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1},
        {1,2,1,1,2,1,1,1,1,1,0,1,1,1,2,1,2,1,1,1,2,1},
        {1,2,1,1,2,2,2,1,0,0,0,0,0,0,2,1,2,2,2,1,2,1},
        {1,2,1,1,2,1,2,1,0,1,1,1,0,1,2,1,2,1,2,1,2,1},
        {1,2,2,2,2,1,2,0,0,1,0,1,0,1,2,2,2,1,2,2,2,1},
        {1,1,1,1,2,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,2,1},
        {1,2,2,2,2,1,2,0,0,1,0,1,0,1,2,2,2,1,2,2,2,1},
        {1,2,1,1,2,1,2,1,0,1,1,1,0,1,2,1,2,1,2,1,2,1},
        {1,2,1,1,2,2,2,1,0,0,0,0,0,0,2,1,2,2,2,1,2,1},
        {1,2,1,1,2,1,1,1,1,1,0,1,1,1,2,1,2,1,1,1,2,1},
        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1},
        {1,2,1,1,2,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,2,1},
        {1,2,1,1,2,1,2,1,0,1,2,1,0,1,2,1,2,2,2,1,2,1},
        {1,2,2,3,2,2,2,1,0,1,2,1,0,1,2,2,3,1,2,2,2,1},
        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };

//    qreal rotacion() const;

    qreal y() const;

    qreal x() const;


    void regla();

signals:

public slots:
    void Actualizacion();
    void movimiento(int _direccion);

   // void setRotacion(qreal newRotacion);

    void setY(qreal newY);

    void setX(qreal newX);



private:
//    enum Posicion{
//        arriba,abajo,izquierda,derecha
//    };
//    void actualizarPixmap();
//    Posicion posicion;


//    qreal m_rotacion;
    qreal m_y;
    qreal m_x;
//    QPropertyAnimation * yanimacion;
//    QPropertyAnimation * xanimacion;
//    QPropertyAnimation * yrotacion;
//    qreal y_ubicacion;
//    qreal x_ubicacion;

};

#endif // PACMAN_H
