#include "widget.h"
#include "ui_widget.h"

#include<QPixmap>
#include"imagenbitmap.h"
#include<QFileDialog>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Ui::Widget *imagen = this->ui;
    ptrBitmap = new ImagenBitmap(imagen);
    ptrDibujar = new Dibujo(this);
    dibujar = false;


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_cargarImagen_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                            ".",
                                                            tr("BMP image (*.bmp)"));
    QPixmap bmpImagen;
    bmpImagen.load(s);
    ptrBitmap->mostrarImagen(bmpImagen);
    //QPixmap image("/home/mimi/Descargas/redPanda.bmp");

}


void Widget::on_lapizButton_clicked()
{

    dibujar = true;
    ptrDibujar->cambiarEstado();
   // ptrDibujar->hacerLineas();

    //ptrDibujar->paintEvent(ui->lapizButton->clicked());
}
