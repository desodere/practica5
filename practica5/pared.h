#ifndef PARED_H
#define PARED_H

#include <QObject>
#include <QPainter>
#include <QImage>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "pacman.h"
#include <iostream>
#include <QDebug>
using namespace std;

class Pared:public QObject, public QGraphicsItem
{
public:
//    Esfera(QWidget *parent = nullptr);
//    ~Esfera();

    Pared(int est,float alt,float anc, float _x, float _y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);


    int getEstado() const;
    void setEstado(int newEstado);

private:
    int estado;
    float altura;
    float ancho;
    float radio;
    float x;
    float y;

signals:

public slots:
    int contacto(Pacman *pac);
};

#endif // PARED_H
