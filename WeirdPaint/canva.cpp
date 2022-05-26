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

void Canva::cambiarEstadoBorrador(std::string clave)
{
    if(clave == "lapiz"){
    borradorEnabled = false;
    }else{
        borradorEnabled = true;
    }
}


void Canva::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        puntoFinal = event->pos();
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
        dibujo = false;
    }
}

void Canva::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
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
    if (borradorEnabled){
        painter.setPen(QPen(Qt::white, grosor, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));


    }else{
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

QImage Canva::mostrarImagen(QImage imagePath)
{
        QImage new_image(imagePath.width(), imagePath.height(), imagePath.format());
        int height_subtraction = imagePath.height() - 1;
        for(int x = 0; x < imagePath.width(); ++x)
            for(int y = 0; y < imagePath.height(); ++y)
                new_image.setPixel(x, height_subtraction - y, imagePath.pixel(x, y));
        return new_image;

}



