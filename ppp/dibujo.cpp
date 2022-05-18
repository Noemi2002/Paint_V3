#include "dibujo.h"



Dibujo::Dibujo(QWidget *parent)
    : QWidget(parent)
{
    //flag = false;
}

void Dibujo::hacerLineas(){

}

void Dibujo::cambiarEstado(){
    //flag = true;

}

void Dibujo::paintEvent(QPaintEvent *event)
{
    //if(!flag){
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
    painter.drawLine(10, 10, 200, 200);



}
