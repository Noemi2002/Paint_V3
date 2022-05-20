#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<dibujo.h>

class ImagenBitmap;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Ui::Widget *ui;


private slots:
    void on_cargarImagen_clicked();
    void on_lapizButton_clicked();
    void on_grosorButton_clicked();
     void on_colorBUtton_clicked();

     void on_borradorButton_clicked();

private:
    ImagenBitmap *ptrBitmap;
    Dibujo *ptrDibujar;
    bool dibujar;

    //
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

};
#endif // WIDGET_H
