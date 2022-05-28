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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , canvaVentana(new Canva(this))
{
    ui->setupUi(this);

    setCentralWidget(canvaVentana);
}


MainWindow::~MainWindow(){}

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

/*void MainWindow::on_actionRect_ngulo_triggered()
{



}*/




void MainWindow::on_actionColor_triggered()
{
    mColor = QColorDialog::getColor(Qt::black, this, "Color de lápiz");
    if (mColor.isValid())
        canvaVentana->cambiarColor(mColor);
}


void MainWindow::on_actionBorrador_triggered()
{
    canvaVentana->cambiarEstadoBorrador("borrador");
    canvaVentana->lapiceroOf();
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





void MainWindow::on_actionCargar_Imagen_triggered()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                            ".",
                                                            tr("BMP image (*.bmp)"));
    QImage bmpImagen;
    bmpImagen.load(s);
    canvaVentana->asignarColoresMatriz(bmpImagen);
}


void MainWindow::on_actionLapicero_triggered()
{

    canvaVentana->lapiceroOn();
    canvaVentana->cambiarEstadoBorrador("null");

}



void MainWindow::on_actionColorPicker_triggered()
{
    canvaVentana->cambiarEstadoColorPicker();
}


void MainWindow::on_actionNegativo_triggered()
{
    canvaVentana->filtroNegativo();
}


void MainWindow::on_actionIntercambio_de_azul_y_rojo_triggered()
{
    canvaVentana->intercambioColores();
}


void MainWindow::on_actionBlanco_y_negro_triggered()
{
    canvaVentana->filtroBlancoNegro();
}


void MainWindow::on_actionC_lido_triggered()
{
    canvaVentana->filtroCalido();
}


void MainWindow::on_actionFiltro_triggered()
{
    canvaVentana->filtroAzul();
}


void MainWindow::on_actionCirculo_triggered()
{
    mCoorX = QInputDialog::getInt(this, "Coordenada_X", "Ingrese la posición en X: ", 0,0);
    mCoorY = QInputDialog::getInt(this, "Coordenada_Y", "Ingrese la posición en Y: ", 0,0);
    mradioX = QInputDialog::getInt(this, "radio_X", "Ingrese el radio en X: ", 0,0);
    mradioY = QInputDialog::getInt(this, "radio_Y", "Ingrese el radio en Y: ", 0,0);

    canvaVentana->cambiarCoorX(mCoorX);
    canvaVentana->cambiarCoorY(mCoorY);
    canvaVentana->cambiarRadioX(mradioX);
    canvaVentana->cambiarRadioY(mradioY);

    canvaVentana->Circulo();
}

void MainWindow::on_actionRectangulo_triggered()
{
    X = QInputDialog::getInt(this, "X", "Ingrese la posición en X: ", 0,0);
    Y = QInputDialog::getInt(this, "Y", "Ingrese la posición en Y: ", 0,0);
    mAncho = QInputDialog::getInt(this, "Ancho", "Ingrese el Altura: ", 0,0);
    mAlto = QInputDialog::getInt(this, "Altura", "Ingrese el Ancho: ", 0,0);

    canvaVentana->cambiarX(X);
    canvaVentana->cambiarY(Y);
    canvaVentana->cambiarAncho(mAncho);
    canvaVentana->cambiarAlto(mAlto);

    canvaVentana->Rectangulo();
}

void MainWindow::on_actionCuadrado_triggered()
{

    XCuad = QInputDialog::getInt(this, "X", "Ingrese la posición en X: ", 0,0);
    YCuad = QInputDialog::getInt(this, "Y", "Ingrese la posición en Y: ", 0,0);
    LadoCuad = QInputDialog::getInt(this, "Ancho", "Ingrese el Altura: ", 0,0);

    canvaVentana->cambiarPosX(XCuad);
    canvaVentana->cambiarPosY(YCuad);

    canvaVentana->cambiarLado(LadoCuad);

    canvaVentana->Cuadrado();
}

