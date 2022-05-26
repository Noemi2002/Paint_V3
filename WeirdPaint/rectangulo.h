#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <QMainWindow>
#include <QPainter>


class Rectangulo
{
public:
    Rectangulo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, QWidget *widget);

protected:
    void mousePressEvent(*event) override;
    void mouseReleaseEvent( event) override;
    bool pressed;
};

#endif // RECTANGULO_H



