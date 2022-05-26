#ifndef FIGURAS_H
#define FIGURAS_H

#include <QMainWindow>

class Figuras : public QMainWindow
{
    Q_OBJECT
public:
    explicit Figuras(QWidget *parent = nullptr);

    void crearCuadrado();
    void crearRectangulo();
    void crearCirculo();
    void crearTriangulo();

signals:

};

#endif // FIGURAS_H
