#include "imagenbitmap.h"
#include<widget.h>
#include <QWidget>
#include"ui_widget.h"



ImagenBitmap::ImagenBitmap(Ui::Widget* ptr)
{
    ptrVentana = ptr;
}
void ImagenBitmap::mostrarImagen(QPixmap imagen)
{
    //ptrVentana->canva->setPixmap(imagen);
    //ui->canva->setPixmap(imagen);
    QPixmap p; // load pixmap
    // get label dimensions
    int w = ptrVentana->canva->width();
    int h = ptrVentana->canva->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ptrVentana->canva->setPixmap(imagen.scaled(w,h,Qt::KeepAspectRatio));
    //ptrVentana->canva->setPixmap(scaledPixmap());
    //QLabel::setPixmap(scaledPixmap());
}
