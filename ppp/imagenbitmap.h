#ifndef IMAGENBITMAP_H
#define IMAGENBITMAP_H

#include"widget.h"
#include<QPixmap>
#include <QWidget>

class Widget;


class ImagenBitmap
{
public:
    ImagenBitmap(Ui::Widget* ptr = nullptr);
    void mostrarImagen(QPixmap imagen);

private slots:




private:
    Ui::Widget *ptrVentana;
    ImagenBitmap *s;
};

#endif // IMAGENBITMAP_H
