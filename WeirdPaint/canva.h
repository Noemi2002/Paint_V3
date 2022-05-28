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

    //Características del lápiz
    void cambiarColor(const QColor &colorSeleccionado);
    void cambiarGrosor(int grosorSeleccionado);
    void cambiarEstadoBorrador(std::string clave);
    void lapiceroOn();
    void lapiceroOf();

    //Características de la imagen
    bool guardarImagen(const QString &fileName, const char *fileFormat);
    void asignarColoresMatriz(QImage imagePath);
    void cambiarEstadoColorPicker();
    void filtroNegativo();
    void filtroBlancoNegro();
    void intercambioColores();
    void filtroCalido();
    void filtroAzul();
    void nuevo();
    bool canvaModificado();

    //Características de las figuras
        //Círculo
    void cambiarCoorX(int CoorXSeleccionado);
    void cambiarCoorY(int CoorYSeleccionado);
    void cambiarRadioY(int RadioYSeleccionado);
    void cambiarRadioX(int RadioXSeleccionado);
    void Circulo();
        //Rectángulo
    void cambiarAlto(int AltoSeleccionado);
    void cambiarAncho(int AnchoSeleccionado);
    void cambiarX(int XSeleccionado);
    void cambiarY(int YSeleccionado);
    void Rectangulo();
        //Cuadrado
    void cambiarPosX(int XCuad);
    void cambiarPosY(int YCuad);
    void cambiarLado(int LadoCuad);
    void Cuadrado();


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;


private:
    //Características de la sección de dibujo
    void dibujarFiguras(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);


    bool modified = false;
    bool dibujo = false;
    bool borradorEnabled = false;
    bool imagenActivada = false;
    bool lapicero;
    bool circulo;
    bool rectangulo;
    bool colorPickerActivado = false;
    bool cuadrado;

    int grosor = DEFAULT_SIZE;
    int CoordenadaX;
    int CoordenadaY;
    int RadioX;
    int RadioY;
    int Ancho;
    int Altura;
    int X;
    int Y;
    int XP;
    int YP;
    int LadoP;

    QPoint Inicio;
    QPoint Final;
    QPoint puntoFinal;

    QImage image;
    QImage direccion;

    QColor color = DEFAULT_COLOR;
    QRgb coloresImagen[1000][1000];
    QSize nuevoTamano;



signals:

};

#endif // CANVA_H




