#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    //setCentralWidget();
    new QPushButton("Botón", this);
}
