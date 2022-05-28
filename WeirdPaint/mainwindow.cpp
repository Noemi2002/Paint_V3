#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
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

/**
 * Cambia el estaod del borrador y el lapiz
 * @brief MainWindow::on_actionL_piz_triggered
 */
void MainWindow::on_actionL_piz_triggered()
{
    canvaVentana->cambiarEstadoBorrador("lapiz");
}

/**
 * @brief MainWindow::on_actionGrosor_triggered
 */
void MainWindow::on_actionGrosor_triggered()
{
    mgrosor = QInputDialog::getInt(this, "Tamaño de lápiz", "Ingrese el tamaño: ", 5, 1);
    canvaVentana->cambiarGrosor(mgrosor);
}

/**
 * @brief MainWindow::on_actionColor_triggered
 */
void MainWindow::on_actionColor_triggered()
{
    mColor = QColorDialog::getColor(Qt::black, this, "Color de lápiz");
    if (mColor.isValid())
        canvaVentana->cambiarColor(mColor);
}

/**
 * @brief MainWindow::on_actionBorrador_triggered
 */
void MainWindow::on_actionBorrador_triggered()
{
    canvaVentana->cambiarEstadoBorrador("borrador");
    canvaVentana->lapiceroOf();
}

/**
 * @brief MainWindow::on_actionGuardar_Imagen_triggered
 * @return
 */
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

/**
 * @brief MainWindow::on_actionCargar_Imagen_triggered
 */
void MainWindow::on_actionCargar_Imagen_triggered()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                            ".",
                                                            tr("BMP image (*.bmp)"));
    QImage bmpImagen;
    bmpImagen.load(s);
    canvaVentana->asignarColoresMatriz(bmpImagen);
}

/**
 * @brief MainWindow::on_actionLapicero_triggered
 */
void MainWindow::on_actionLapicero_triggered()
{
    canvaVentana->lapiceroOn();
    canvaVentana->cambiarEstadoBorrador("null");
}

/**
 * @brief MainWindow::on_actionColorPicker_triggered
 */
void MainWindow::on_actionColorPicker_triggered()
{
    canvaVentana->cambiarEstadoColorPicker();
}

/**
 * @brief MainWindow::on_actionNegativo_triggered
 */
void MainWindow::on_actionNegativo_triggered()
{
    canvaVentana->filtroNegativo();
}

/**
 * @brief MainWindow::on_actionIntercambio_de_azul_y_rojo_triggered
 */
void MainWindow::on_actionIntercambio_de_azul_y_rojo_triggered()
{
    canvaVentana->intercambioColores();
}

/**
 * @brief MainWindow::on_actionBlanco_y_negro_triggered
 */
void MainWindow::on_actionBlanco_y_negro_triggered()
{
    canvaVentana->filtroBlancoNegro();
}

/**
 * @brief MainWindow::on_actionC_lido_triggered
 */
void MainWindow::on_actionC_lido_triggered()
{
    canvaVentana->filtroCalido();
}

/**
 * @brief MainWindow::on_actionFiltro_triggered
 */
void MainWindow::on_actionFiltro_triggered()
{
    canvaVentana->filtroAzul();
}

/**
 * @brief MainWindow::on_actionCirculo_triggered
 */
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

/**
 * @brief MainWindow::on_actionRectangulo_triggered
 */
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

/**
 * @brief MainWindow::on_actionCuadrado_triggered
 */
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

