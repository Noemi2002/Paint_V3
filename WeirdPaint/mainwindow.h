#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_actionL_piz_triggered();
    void on_actionColor_triggered();
    void on_actionGrosor_triggered();
    void on_actionBorrador_triggered();
    bool on_actionGuardar_Imagen_triggered();


    //void on_actionRect_ngulo_triggered();


    void on_actionCargar_Imagen_triggered();

    void on_actionLapicero_triggered();

<<<<<<< Updated upstream
    void on_actionColorPicker_triggered();

    void on_actionNegativo_triggered();

    void on_actionIntercambio_de_azul_y_rojo_triggered();

    void on_actionBlanco_y_negro_triggered();

    void on_actionC_lido_triggered();

    void on_actionFiltro_triggered();
=======
    void on_actionCirculo_triggered();

    void on_actionRectangulo_triggered();

    void on_actionCuadrado_triggered();
>>>>>>> Stashed changes

private:
    QPainter *mPainter;
    QImage *mImage;
    QPoint mBegin;
    QPoint mEnd;
    bool mEnabled;
    QColor mColor;
    int mgrosor;
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


    bool borradorEnabled;


    Canva *canvaVentana;


/*protected:
   void paintEvent(QPaintEvent *) override;
   void mousePressEvent(QMouseEvent *e) override;
   void mouseMoveEvent(QMouseEvent *e) override;
   void mouseReleaseEvent(QMouseEvent *e) override;*/


private:
    Ui::MainWindow *ui;
    //Imagen *ptrImagen;
};
#endif // MAINWINDOW_H
