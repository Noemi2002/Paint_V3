#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canva.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void crearBotones();

private:
    Ui::MainWindow *ui;
    canva *Canva;

    //Botones
    QPushButton *cargarImagenButton;
    QPushButton *guardarImagenButton;
    QPushButton *lapizButton;
    QPushButton *lapiceroButton;
    QPushButton *borradorButton;
    QPushButton *colorButton;
    QPushButton *grosorButton;

};
#endif // MAINWINDOW_H
