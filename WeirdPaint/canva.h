#ifndef CANVA_H
#define CANVA_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>

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

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void dibujarFiguras(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified = false;
    bool dibujo = false;
    bool borradorEnabled = false;
    int grosor = DEFAULT_SIZE;
    QColor color = DEFAULT_COLOR;
    QImage image;
    QPoint puntoFinal;

signals:

};

#endif // CANVA_H




