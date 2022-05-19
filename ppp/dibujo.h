#ifndef DIBUJO_H
#define DIBUJO_H

#include <QObject>
#include<QWidget>

#include<QPainter>
#include<QPaintEvent>

class Dibujo : public QWidget
{
    Q_OBJECT


public:
    explicit Dibujo(QWidget *parent);

    void hacerLineas();
    void cambiarEstado();

private:
    bool flag;

protected:
   //void paintEvent(QPaintEvent *);
};

#endif // DIBUJO_H
