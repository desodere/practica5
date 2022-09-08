#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Pacman : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotacion READ rotacion WRITE setRotacion)
    Q_PROPERTY(qreal y READ y WRITE setY)
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit Pacman(QPixmap pixmap);

    qreal rotacion() const;

    qreal y() const;

    qreal x() const;

    void ir_arriba();
    void ir_abajo();
    void ir_derecha();
    void ir_izquierda();




signals:

public slots:
    void setRotacion(qreal newRotacion);

    void setY(qreal newY);

    void setX(qreal newX);

    void rotateTo(const qreal &end, const int& duracion,
                  const QEasingCurve& curve);

private:
    enum Posicion{
        arriba,abajo,izquierda,derecha
    };
    void actualizarPixmap();
    Posicion posicion;
    int direccion;

    qreal m_rotacion;
    qreal m_y;
    qreal m_x;
    QPropertyAnimation * yanimacion;
    QPropertyAnimation * xanimacion;
    QPropertyAnimation * yrotacion;
    qreal y_ubicacion;
    qreal x_ubicacion;

};

#endif // PACMAN_H
