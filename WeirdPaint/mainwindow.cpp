#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QFileDialog>

#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QInputDialog>
#include <QColorDialog>

#include <QString>
#include <QByteArray>

#include "rectangulo.h"

#define DEFAULT_SIZE 5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mImage = new QImage(QApplication::desktop()->size(), QImage::Format_ARGB32_Premultiplied);
    mImage->fill(Qt::white);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::black);
    mgrosor = DEFAULT_SIZE;

    borradorEnabled = false;
    ptrCanva = new Canva(this);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete mPainter;
    delete mImage;

}



void MainWindow::on_actionL_piz_triggered()
{
    borradorEnabled = false;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(mImage->rect(), Qt::white);
    //QPainter painter( );
    painter.drawImage(0, 0, *mImage);
    event->accept();

}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    mEnabled = true;
    //borradorEnabled= true;
    mBegin = e->pos();
    e->accept(); //Hace que se termine de ejecutar, como que se cierre el método
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
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

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    mEnabled = false;
    e->accept();
}

void MainWindow::on_actionGrosor_triggered()
{
    mgrosor = QInputDialog::getInt(this, "Tamaño de lápiz", "Ingrese el tamaño: ", 5, 1);
}

void MainWindow::on_actionColor_triggered()
{
    mColor = QColorDialog::getColor(Qt::black, this, "Color de lápiz");
}



void MainWindow::on_actionBorrador_triggered()
{
    borradorEnabled = true;
    mEnabled = false;

    update();
}


bool MainWindow::on_actionGuardar_Imagen_triggered()
{
    QByteArray formatoImage = "bmp";
    QString initialPath = QDir::currentPath() + "/untitled." + formatoImage;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString::fromLatin1(formatoImage.toUpper()))
                               .arg(QString::fromLatin1(formatoImage)));
    if (fileName.isEmpty())
        return false;
    return guardarImagen(fileName, formatoImage.constData());
}

bool MainWindow::guardarImagen(const QString &fileName, const char *fileFormat)
{

    QImage visibleImage = *mImage;
    //resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        //modified = false;
        return true;
    }
    return false;
}


void MainWindow::on_actionRect_ngulo_triggered()
{
    //scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);

    Rectangulo square = new Rectangulo;
    //scene->addItem(square);
}

