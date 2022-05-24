#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Canva(new canva(this))
{
    ui->setupUi(this);
    setCentralWidget(Canva);
    crearBotones();


    //resize(5000, 500);
}

void MainWindow::crearBotones()
{
    cargarImagenButton = new QPushButton("Cargar Imagen", this);
    cargarImagenButton->setGeometry(QRect( QPoint(10, 10), QSize(108, 25)));

    guardarImagenButton = new QPushButton("Guardar Imagen", this);
    guardarImagenButton->setGeometry(QRect( QPoint(10, 111), QSize(111, 25)));

    lapizButton = new QPushButton("Lápiz", this);
    lapizButton->setGeometry(QRect( QPoint(10, 100), QSize(111, 25)));

    lapiceroButton = new QPushButton("Lapicero", this);
    lapiceroButton->setGeometry(QRect( QPoint(10, 130), QSize(111, 25)));

    borradorButton = new QPushButton("Borrador", this);
    borradorButton->setGeometry(QRect( QPoint(10, 160), QSize(111, 25)));

    colorButton = new QPushButton("", this);
    colorButton->setGeometry(QRect( QPoint(10, 190), QSize(111, 25)));

    grosorButton = new QPushButton("Cargar Imagen", this);
    grosorButton->setGeometry(QRect( QPoint(10, 220), QSize(111, 25)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

