#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<dibujo.h>

class ImagenBitmap;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Ui::Widget *ui;


private slots:

    void on_cargarImagen_clicked();

    void on_lapizButton_clicked();

private:

    ImagenBitmap *ptrBitmap;
    Dibujo *ptrDibujar;
    bool dibujar;

};
#endif // WIDGET_H
