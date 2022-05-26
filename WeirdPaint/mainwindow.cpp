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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , canvaVentana(new Canva(this))
{
    ui->setupUi(this);
    setCentralWidget(canvaVentana);
    //borradorEnabled = false;

}


MainWindow::~MainWindow()
{
}



void MainWindow::on_actionL_piz_triggered()
{
    canvaVentana->cambiarEstadoBorrador("lapiz");
    //borradorEnabled = false;
}


void MainWindow::on_actionGrosor_triggered()
{
    mgrosor = QInputDialog::getInt(this, "Tamaño de lápiz", "Ingrese el tamaño: ", 5, 1);
    canvaVentana->cambiarGrosor(mgrosor);

}

void MainWindow::on_actionColor_triggered()
{
    mColor = QColorDialog::getColor(Qt::black, this, "Color de lápiz");
    if (mColor.isValid())
        canvaVentana->cambiarColor(mColor);

}



void MainWindow::on_actionBorrador_triggered()
{
    canvaVentana->cambiarEstadoBorrador("borrador");
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
    return canvaVentana->guardarImagen(fileName, formatoImage.constData());
}



void MainWindow::on_actionRect_ngulo_triggered()
{
    //scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);

    //Rectangulo square = new Rectangulo;
    //scene->addItem(square);
}









