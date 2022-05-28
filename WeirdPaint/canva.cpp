#include "canva.h"
#include <QImage>



Canva::Canva(QWidget *parent)
    : QWidget{parent}
{
    (Qt::WA_StaticContents);
    borradorEnabled = false;
}

/**
 * @brief Canva::cambiarColor
 * @param colorSeleccionado
 */
void Canva::cambiarColor(const QColor &colorSeleccionado)
{
    color = colorSeleccionado;
}

/**
 * @brief Canva::cambiarGrosor
 * @param grosorSeleccionado
 */
void Canva::cambiarGrosor(int grosorSeleccionado)
{
    grosor = grosorSeleccionado;
}

/**
 * @brief Canva::cambiarEstadoColorPicker
 */
void Canva::cambiarEstadoColorPicker()
{
    colorPickerActivado = true;
}

/**
 * @brief Canva::cambiarCoorX
 * @param CoorXSeleccionado
 */
void Canva::cambiarCoorX(int CoorXSeleccionado)
{
    CoordenadaX = CoorXSeleccionado;
}

/**
 * @brief Canva::cambiarCoorY
 * @param CoorYSeleccionado
 */
void Canva::cambiarCoorY(int CoorYSeleccionado)
{
    CoordenadaY = CoorYSeleccionado;
}

/**
 * @brief Canva::cambiarRadioX
 * @param RadioXSeleccionado
 */
void Canva::cambiarRadioX(int RadioXSeleccionado)
{
   RadioX = RadioXSeleccionado;
}

/**
 * @brief Canva::cambiarRadioY
 * @param RadioYSeleccionado
 */
void Canva::cambiarRadioY(int RadioYSeleccionado)
{
    RadioY = RadioYSeleccionado;
}

/**
 * @brief Canva::cambiarAncho
 * @param AnchoSeleccionado
 */
void Canva::cambiarAncho(int AnchoSeleccionado)
{
  Ancho = AnchoSeleccionado;
}

/**
 * @brief Canva::cambiarAlto
 * @param AlturaSeleccionado
 */
void Canva::cambiarAlto(int AlturaSeleccionado)
{
    Altura = AlturaSeleccionado;
}

/**
 * @brief Canva::cambiarX
 * @param XSeleccionado
 */
void Canva::cambiarX(int XSeleccionado)
{
  X = XSeleccionado;
}

/**
 * @brief Canva::cambiarY
 * @param YSeleccionado
 */
void Canva::cambiarY(int YSeleccionado)
{
    Y = YSeleccionado;
}

/**
 * @brief Canva::cambiarPosX
 * @param PosXSeleccionado
 */
void Canva::cambiarPosX(int PosXSeleccionado)
{
    XP = PosXSeleccionado;
}

/**
 * @brief Canva::cambiarPosY
 * @param PosYSeleccionado
 */
void Canva::cambiarPosY(int PosYSeleccionado)
{
    YP = PosYSeleccionado;
}

/**
 * @brief Canva::cambiarLado
 * @param LadoCuad
 */
void Canva::cambiarLado(int LadoCuad)
{
    LadoP = LadoCuad;
}

/**
 * @brief Canva::cambiarEstadoBorrador
 * @param clave
 */
void Canva::cambiarEstadoBorrador(std::string clave)
{
    if(clave == "lapiz"){
    lapicero = false;
    borradorEnabled = false;
    }else{
        borradorEnabled = true;
    }
}

/**
 * @brief Canva::mousePressEvent
 * @param event
 */
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

/**
 * @brief Canva::mouseMoveEvent
 * @param event
 */
void Canva::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dibujo)
        dibujarFiguras(event->pos());
}

/**
 * @brief Canva::mouseReleaseEvent
 * @param event
 */
void Canva::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dibujo) {
        Final = event->pos();
        dibujarFiguras(Final);
        dibujo = false;
        Inicio=Final;
        update();
    }
}

/**
 * @brief Canva::paintEvent
 * @param event
 */
void Canva::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (imagenActivada){
        for (int i = 0; i < direccion.width(); i++)
        {
            for(int j = 0;j < direccion.height(); j++)
            {
                image.setPixel (i, j, coloresImagen[i][j]);
            }
        }
        painter.drawImage(10, 10, image);
        imagenActivada = false;
       }else{
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);

    }
}

/**
 * @brief Canva::resizeEvent
 * @param event
 */
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

/**
 * @brief Canva::dibujarFiguras
 * @param endPoint
 */
void Canva::dibujarFiguras(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(color, grosor, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    if (lapicero)
        {
         painter.drawLine(Final,Inicio);
        }
    if (circulo)
    {
        painter.drawEllipse(CoordenadaX,CoordenadaY,RadioX,RadioY);
         }
    if(rectangulo)
    {
        painter.drawRect(X,Y,Ancho,Altura);
    }

    if(cuadrado)
    {
        painter.drawRect(XP,YP,LadoP,LadoP);
    }
    if (borradorEnabled)
    {
        painter.setPen(QPen(Qt::white, grosor, Qt::SolidLine, Qt::RoundCap,
                            Qt::RoundJoin));
        }
    painter.drawLine(puntoFinal, endPoint);
    modified = true;
    int rad = (grosor / 2) + 2;
    update(QRect(puntoFinal, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    puntoFinal = endPoint;
}

/**
 * @brief Canva::resizeImage
 * @param image
 * @param newSize
 */
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

/**
 * @brief Canva::guardarImagen
 * @param fileName
 * @param fileFormat
 * @return
 */
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

/**
 * @brief Canva::asignarColoresMatriz
 * @param imagePath
 */
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

/**
 * @brief Canva::lapiceroOn
 */
void Canva::lapiceroOn()
{
    lapicero = true;
    borradorEnabled = false;
}

/**
 * @brief Canva::lapiceroOf
 */
void Canva::lapiceroOf()
{
    lapicero = false;
}

/**
 * @brief Canva::Circulo
 */
void Canva::Circulo()
{
    lapicero = false;
    borradorEnabled = false;
    circulo = true;
}

/**
 * @brief Canva::Rectangulo
 */
void Canva::Rectangulo()
{
    lapicero = false;
    borradorEnabled = false;
    rectangulo = true;
}

/**
 * @brief Canva::filtroNegativo
 */
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

/**
 * @brief Canva::filtroBlancoNegro
 */
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

/**
 * @brief Canva::intercambioColores
 */
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

/**
 * @brief Canva::filtroCalido
 */
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

/**
 * @brief Canva::filtroAzul
 */
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

/**
 * @brief Canva::Cuadrado
 */
void Canva::Cuadrado()
{
    lapicero = false;
    borradorEnabled = false;
    cuadrado = true;
}

/**
 * @brief Canva::nuevo
 */
void Canva::nuevo()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

/**
 * @brief Canva::canvaModificado
 * @return
 */
bool Canva::canvaModificado(){
    return modified;
}
