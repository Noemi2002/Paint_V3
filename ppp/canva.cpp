#include "canva.h"

Canva::Canva(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StaticContents);
}

void Canva::print()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printdialog)
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog printDialog(&printer, this);

    if (printDialog.exec() == QDialog::Accepted) {
           QPainter painter(&printer);
           QRect rect = painter.viewport();
           QSize size = image.size();
           size.scale(rect.size(), Qt::KeepAspectRatio);
           painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
           painter.setWindow(image.rect());
           painter.drawImage(0, 0, image);
       }
   #endif // QT_CONFIG(printdialog)
}
