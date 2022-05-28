#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "canva.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    //Funcionalidades básicas
    void on_actionL_piz_triggered();
    void on_actionColor_triggered();
    void on_actionGrosor_triggered();
    void on_actionBorrador_triggered();
    bool on_actionGuardar_Imagen_triggered();
    void on_actionCargar_Imagen_triggered();
    void on_actionLapicero_triggered();
    void on_actionColorPicker_triggered();
    void on_actionNegativo_triggered();
    void on_actionIntercambio_de_azul_y_rojo_triggered();
    void on_actionBlanco_y_negro_triggered();
    void on_actionC_lido_triggered();
    void on_actionFiltro_triggered();
    void on_actionCirculo_triggered();
    void on_actionRectangulo_triggered();
    void on_actionCuadrado_triggered();
    void on_actionNuevo_triggered();

    bool cerrar();

protected:
    void closeEvent(QCloseEvent *event);



private:
    //Características del lápiz
    QColor mColor;
    int mgrosor;

    //Datos para las figuras
    int mCoorX;
    int mCoorY;
    int mradioX;
    int mradioY;

    int X;
    int Y;
    int mAncho;
    int mAlto;

    int XCuad;
    int YCuad;
    int LadoCuad;


    //Canvas
    Canva *canvaVentana;



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
