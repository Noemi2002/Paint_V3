#include "canva.h"
#include <QImage>



Canva::Canva(QWidget *parent)
    : QWidget{parent}
{
    (Qt::WA_StaticContents);
    borradorEnabled = false;
}

void Canva::cambiarColor(const QColor &colorSeleccionado)
{
    color = colorSeleccionado;
}

void Canva::cambiarGrosor(int grosorSeleccionado)
{
    grosor = grosorSeleccionado;
}

void Canva::cambiarEstadoColorPicker()
{
    colorPickerActivado = true;
}

void Canva::cambiarEstadoBorrador(std::string clave)
{
    if(clave == "lapiz"){
    lapicero = false;
    borradorEnabled = false;
    }else{
        borradorEnabled = true;

    }
}


void Canva::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
            puntoFinal = event->pos();
            if(colorPickerActivado){
                int x = puntoFinal.x();
                int y = puntoFinal.y();
                QColor coloPickerColor = image.pixelColor(x, y);
                cambiarColor(coloPickerColor);
                colorPickerActivado = false;

        }
            dibujo = true;
        }
}

void Canva::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dibujo)
        dibujarFiguras(event->pos());


}

void Canva::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dibujo) {
        dibujarFiguras(event->pos());
        //event->accept();
        update();
        Final = event->pos();
        dibujo = false;
        Inicio=Final;
    }
}

void Canva::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (imagenActivada){
        int height_subtraction = direccion.height() - 1;


        for (int i = 0; i < direccion.width(); i++)
        {
            for(int j = 0;j < direccion.height(); j++)
            {
                image.setPixel (i, height_subtraction - j, coloresImagen[i][j]);
            }
        }


        // Dibuja la imagen en la ventana
        painter.drawImage(10, 10, image);
        imagenActivada = false;
       }


    else{

    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
    }





}

void Canva::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int ventanaAncho = qMax(width() + 128, image.width());
        int ventanaAlto = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(ventanaAncho, ventanaAlto));
        update();
    }
    QWidget::resizeEvent(event);
}

void Canva::dibujarFiguras(const QPoint &endPoint)
{
    QPainter painter(&image);

    if (lapicero)
        {
        painter.setPen(QPen(color, grosor, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
         painter.drawLine(Final,Inicio);
        }

    if (rectangulo)

    {
         painter.drawEllipse(76,27,20,20);
         painter.setPen(QPen(color, grosor, Qt::SolidLine, Qt::RoundCap,
                             Qt::RoundJoin));
    }


    if (borradorEnabled){
        rectangulo = false;

        painter.setPen(QPen(Qt::white, grosor, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
        }

    else{
        painter.setPen(QPen(color, grosor, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
    }

    painter.drawLine(puntoFinal, endPoint);
    modified = true;
    int rad = (grosor / 2) + 2;
    update(QRect(puntoFinal, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    puntoFinal = endPoint;
}

void Canva::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

bool Canva::guardarImagen(const QString &fileName, const char *fileFormat)
{

    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    }
    return false;
}

void Canva::asignarColoresMatriz(QImage imagePath)
{
        direccion = imagePath;
        imagenActivada = true;
        coloresImagen[direccion.width()][direccion.height()];
        for (int i = 0; i < direccion.width(); i++)
        {
            for (int j = 0; j < direccion.height(); j++)
            {
                coloresImagen[i][j] = imagePath.pixelColor(i, j).QColor::rgb();
            }
        }
        update();

}

void Canva::lapiceroOn()
{
    lapicero = true;
    borradorEnabled = false;
}

void Canva::lapiceroOf()
{
    lapicero = false;

}


void Canva::Rectangulo()
{
    lapicero = false;
    borradorEnabled = false;
    rectangulo = true;
}

void Canva::filtroNegativo()
{

    for (int i = 0; i < direccion.width(); i++)
    {
        for (int j = 0; j < direccion.height(); j++)
        {
            QRgb nuevoColor = 255 - coloresImagen[i][j];
            coloresImagen[i][j] = nuevoColor;
        }
    }
    imagenActivada = true;
    update();
}

void Canva::filtroBlancoNegro()
{
    for (int i = 0; i < direccion.width(); i++)
    {
        for (int j = 0; j < direccion.height(); j++)
        {

            QColor nueva =direccion.pixelColor(i, j);
            int blue = nueva.blue();
            int green = nueva.green();
            int red = nueva.red();
            int gris = (red + green + blue) / 3;
            coloresImagen[i][j] = qRgb(gris, gris, gris);
        }
    }
    imagenActivada = true;
    update();
}

void Canva::intercambioColores()
{
    QImage nueva = direccion.rgbSwapped();
    for (int i = 0; i <+ nueva.width(); i++)
    {
        for (int j = 0; j <+ nueva.height(); j++)
        {

            coloresImagen[i][j] = nueva.pixelColor(i, j).QColor::rgb();
        }
    }
    imagenActivada = true;
    update();
}

void Canva::filtroCalido()
{
    for (int i = 0; i < direccion.width(); i++)
    {
        for (int j = 0; j < direccion.height(); j++)
        {
            QRgb nuevoColor = 100 - coloresImagen[i][j];
            coloresImagen[i][j] = nuevoColor;
        }
    }
    imagenActivada = true;
    update();
}

void Canva::filtroAzul()
{
    for (int i = 0; i < direccion.width(); i++)
    {
        for (int j = 0; j < direccion.height(); j++)
        {
            QRgb nuevoColor = 244 + coloresImagen[i][j];
            coloresImagen[i][j] = nuevoColor;
        }
    }
    imagenActivada = true;
    update();
}
