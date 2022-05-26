#include "rectangulo.h"
#include "mainwindow.h"

Rectangulo::Rectangulo()
{
    pressed = false;
    setFlag(ItemIsMovable);
}


QRectF Rectangulo::boundingRect() const
{
    return QRectF(100,50,100,50);//tamaño de la figura

}

void Rectangulo::paint(QPainter *painter, QWidget *widget)
{

    QRectF rec = boundingRect();
    painter->drawRect(rec);
}

void Rectangulo::mousePressEvent(QImageEvent event)
{
    pressed = true;
    update();
    //QGraphicsItem::mousePressEvent(event);
}

void Rectangulo::mouseReleaseEvent(event)
{
    pressed = false;
    update();
    //QGraphicsItem::mouseReleaseEvent(event);
}

