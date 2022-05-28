#include "dibujo.h"



Dibujo::Dibujo(QWidget *parent)
    : QWidget(parent)
{
    //flag = false;
}

void Dibujo::hacerLineas(){
    QPainter painter(this );
    painter.drawLine(10,10,100,100);
}

void Dibujo::cambiarEstado(){
    //flag = true;

}

/*void Dibujo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this );
    painter.drawLine(10,10,100,100);


}*/
