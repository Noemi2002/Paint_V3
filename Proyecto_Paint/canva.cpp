#include "canva.h"
#include <QPainter>
#include <QPaintEvent>

canva::canva(QWidget *parent)
    : QMainWindow{parent}
{
    setAttribute(Qt::WA_StaticContents);
}

