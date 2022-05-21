#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>
#include <QPixmap>
#include "ui_widget.h"

class Image : public QWidget
{
    Q_OBJECT
public:
    explicit Image(QWidget *parent = nullptr, Ui::Widget *ventana2 = nullptr);
    void mostrarImagen(QImage imagePath);


private:
    Ui::Widget *ventana;

signals:

};

#endif // IMAGE_H
