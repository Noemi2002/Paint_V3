#include "image.h"
#include <QImage>
#include <QPixmap>
#include <QGraphicsView>


Image::Image(QWidget *parent, Ui::Widget *ventana2)
    : QWidget{parent}
{
    ventana = ventana2;
}

void Image::mostrarImagen(QImage imagePath)
{
  QGraphicsView *backGroung = ventana->canva;
  QGraphicsScene *scene = new QGraphicsScene();
  QImage *image = new QImage(imagePath);
  scene->addPixmap(QPixmap::fromImage(*image));
  backGroung->setScene(scene);
  backGroung->show();
}
