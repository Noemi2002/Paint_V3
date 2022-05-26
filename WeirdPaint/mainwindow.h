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

    bool guardarImagen(const QString &fileName, const char *fileFormat);

    void on_actionRect_ngulo_triggered();

private:
    QPainter *mPainter;
    QImage *mImage;
    QPoint mBegin;
    QPoint mEnd;
    bool mEnabled;
    QColor mColor;
    int mgrosor;
    bool borradorEnabled;

protected:
   void paintEvent(QPaintEvent *) override;
   void mousePressEvent(QMouseEvent *e) override;
   void mouseMoveEvent(QMouseEvent *e) override;
   void mouseReleaseEvent(QMouseEvent *e) override;


private:
    Ui::MainWindow *ui;
    Canva *ptrCanva;
};
#endif // MAINWINDOW_H
