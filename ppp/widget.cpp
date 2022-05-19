#include "widget.h"
#include "ui_widget.h"

#include<QPixmap>
#include"imagenbitmap.h"
#include<QFileDialog>

#include<QDesktopWidget>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include<QImage>
#include<QInputDialog>
#include<QColorDialog>

#define DEFAULT_SIZE 5



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Ui::Widget *imagen = this->ui;
    ptrBitmap = new ImagenBitmap(imagen);
    ptrDibujar = new Dibujo(this);
    dibujar = false;

    mImage = new QImage(QApplication::desktop()->size(), QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::black);
    mgrosor = DEFAULT_SIZE;


}

Widget::~Widget()
{
    delete ui;
    delete mPainter;
    delete mImage;

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


    //Dibujar rectángulo
    /*int h = ui->canva->height();
      int w = ui->canva->width();
      QPixmap pix(w, h);
      QPainter paint(&pix);
      pix.fill( Qt::white );
      paint.setPen(QColor(0, 0, 0, 255));
      paint.drawRect(QRect(80,120,200,100));
      ui->canva->setPixmap(pix);*/
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this );
    painter.drawImage(0, 0, *mImage);
    event->accept();

}

void Widget::mousePressEvent(QMouseEvent *e)
{
    mEnabled = true;
    mBegin = e->pos();
    e->accept(); //Hace que se termine de ejecutar, como que se cierre el método
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(!mEnabled){
        e->accept();
        return;
    }
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mgrosor);
    mEnd = e->pos();
    mPainter->setPen(pen);
    mPainter->drawLine(mBegin, mEnd);
    mBegin = mEnd;
    update(); //Hace que se ejecute paintEvent
    e->accept();
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    mEnabled = false;
    e->accept();
}

void Widget::on_grosorButton_clicked()
{
    mgrosor = QInputDialog::getInt(this, "Tamaño de lápiz", "Ingrese el tamaño: ", 5, 1);
}

void Widget::on_colorBUtton_clicked()
{
    mColor = QColorDialog::getColor(Qt::black, this, "Color de lápiz");
}

