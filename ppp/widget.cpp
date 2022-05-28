#include "widget.h"
#include "ui_widget.h"

#include <QPixmap>
#include "image.h"
#include <QFileDialog>

#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QInputDialog>
#include <QColorDialog>

#define DEFAULT_SIZE 5



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , canva(new Canva(this))
{
    ui->setupUi(this);

            //setCentralWidget(canva);
    Ui::Widget *ptrVentana = this->ui;
    ptrBitmap = new Image(this, ptrVentana);
    dibujar = false;


    mImage = new QImage(QApplication::desktop()->size(), QImage::Format_ARGB32_Premultiplied);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::black);
    mgrosor = DEFAULT_SIZE;

    borradorEnabled = false;
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
    QImage bmpImagen;
    bmpImagen.load(s);
    ptrBitmap->mostrarImagen(bmpImagen);
    //QPixmap image("/home/mimi/Descargas/redPanda.bmp");

}


void Widget::on_lapizButton_clicked()
{
    borradorEnabled = false;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //QPainter painter( );
    painter.drawImage(0, 0, *mImage);
    event->accept();

}

void Widget::mousePressEvent(QMouseEvent *e)
{
    mEnabled = true;
    //borradorEnabled= true;
    mBegin = e->pos();
    e->accept(); //Hace que se termine de ejecutar, como que se cierre el método
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(!mEnabled){
        e->accept();
        return;
    }

    if(borradorEnabled){
        //borradorEnabled= true;
        //mEnabled = false;
        QPen pen(Qt::white);
        pen.setCapStyle(Qt::RoundCap);
        pen.setWidth(mgrosor);
        mEnd = e->pos();
        mPainter->setPen(pen);
        mPainter->drawLine(mBegin, mEnd);
        mBegin = mEnd;
        update(); //Hace que se ejecute paintEvent
        e->accept();
        //
    }

    if(lineaEnabled){
        //borradorEnabled= true;
        //mEnabled = false;
        QPen pen(Qt::green);
        pen.setCapStyle(Qt::RoundCap);
        pen.setWidth(mgrosor);
        mEnd = e->pos();
        mPainter->setPen(pen);
        rect-> rect (mBegin, mEnd);
        mBegin = mEnd;
        update(); //Hace que se ejecute paintEvent
        e->accept();
        //
    }



    else
        {
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


}

void LineTool::drawTo(const QPoint &mEnd)
    QPainter pa(this);
    pa.setPen(static_cast<QPen>(*this));
    pa.drawLine(getStartPoint(), endPoint);
    update();
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

void Widget::on_borradorButton_clicked()
{
    borradorEnabled = true;
    mEnabled = false;

    update();
}




void Widget::on_linea_clicked()

{
    LineTool()
    lineaEnabled = true;
}
