#ifndef CANVA_H
#define CANVA_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QRgb>



#define DEFAULT_COLOR Qt::black
#define DEFAULT_SIZE 5


class Canva : public QWidget
{
    Q_OBJECT
public:
    explicit Canva(QWidget *parent = nullptr);

    void cambiarColor(const QColor &colorSeleccionado);
    void cambiarGrosor(int grosorSeleccionado);
    void cambiarEstadoBorrador(std::string clave);
    bool guardarImagen(const QString &fileName, const char *fileFormat);
    void asignarColoresMatriz(QImage imagePath);

    void lapiceroOn();
     void lapiceroOf();
    void Rectangulo();
    //QImage mostrarImagen(QImage imagePath);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    //void paintEvent(QPaintEvent *event, QImage filename);


private:
    void dibujarFiguras(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified = false;
    bool dibujo = false;
    bool borradorEnabled = false;
    bool imagenActivada = false;
    QPoint Inicio;
    QPoint Final;
    int grosor = DEFAULT_SIZE;
    QColor color = DEFAULT_COLOR;
    QImage image;
    QPoint puntoFinal;
    QImage direccion;
    bool lapicero;
    bool rectangulo;

    QRgb coloresImagen[2000][2000];



signals:

};

#endif // CANVA_H




