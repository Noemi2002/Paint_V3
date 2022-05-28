/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCargar_Imagen;
    QAction *actionGuardar_Imagen;
    QAction *actionL_piz;
    QAction *actionLapicero;
    QAction *actionBorrador;
    QAction *actionGrosor;
    QAction *actionColor;
    QAction *actionRect_ngulo;
    QAction *actionTri_ngulo;
    QAction *actionC_rculo;
    QAction *actionFill;
    QAction *actionColorPicker;
    QAction *actionBlanco_y_negro;
    QAction *actionNegativo;
    QAction *actionNuevo;
    QAction *actionIntercambio_de_azul_y_rojo;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuCartuchera;
    QMenu *menuCaracter_sticas;
    QMenu *menuFiguras;
    QMenu *menuPintar;
    QMenu *menuFiltros;
    QMenu *menuUndo;
    QMenu *menuRedo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionCargar_Imagen = new QAction(MainWindow);
        actionCargar_Imagen->setObjectName(QString::fromUtf8("actionCargar_Imagen"));
        actionGuardar_Imagen = new QAction(MainWindow);
        actionGuardar_Imagen->setObjectName(QString::fromUtf8("actionGuardar_Imagen"));
        actionL_piz = new QAction(MainWindow);
        actionL_piz->setObjectName(QString::fromUtf8("actionL_piz"));
        actionLapicero = new QAction(MainWindow);
        actionLapicero->setObjectName(QString::fromUtf8("actionLapicero"));
        actionBorrador = new QAction(MainWindow);
        actionBorrador->setObjectName(QString::fromUtf8("actionBorrador"));
        actionGrosor = new QAction(MainWindow);
        actionGrosor->setObjectName(QString::fromUtf8("actionGrosor"));
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName(QString::fromUtf8("actionColor"));
        actionRect_ngulo = new QAction(MainWindow);
        actionRect_ngulo->setObjectName(QString::fromUtf8("actionRect_ngulo"));
        actionTri_ngulo = new QAction(MainWindow);
        actionTri_ngulo->setObjectName(QString::fromUtf8("actionTri_ngulo"));
        actionC_rculo = new QAction(MainWindow);
        actionC_rculo->setObjectName(QString::fromUtf8("actionC_rculo"));
        actionFill = new QAction(MainWindow);
        actionFill->setObjectName(QString::fromUtf8("actionFill"));
        actionColorPicker = new QAction(MainWindow);
        actionColorPicker->setObjectName(QString::fromUtf8("actionColorPicker"));
        actionBlanco_y_negro = new QAction(MainWindow);
        actionBlanco_y_negro->setObjectName(QString::fromUtf8("actionBlanco_y_negro"));
        actionNegativo = new QAction(MainWindow);
        actionNegativo->setObjectName(QString::fromUtf8("actionNegativo"));
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QString::fromUtf8("actionNuevo"));
        actionIntercambio_de_azul_y_rojo = new QAction(MainWindow);
        actionIntercambio_de_azul_y_rojo->setObjectName(QString::fromUtf8("actionIntercambio_de_azul_y_rojo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuCartuchera = new QMenu(menubar);
        menuCartuchera->setObjectName(QString::fromUtf8("menuCartuchera"));
        menuCaracter_sticas = new QMenu(menubar);
        menuCaracter_sticas->setObjectName(QString::fromUtf8("menuCaracter_sticas"));
        menuFiguras = new QMenu(menubar);
        menuFiguras->setObjectName(QString::fromUtf8("menuFiguras"));
        menuPintar = new QMenu(menubar);
        menuPintar->setObjectName(QString::fromUtf8("menuPintar"));
        menuFiltros = new QMenu(menubar);
        menuFiltros->setObjectName(QString::fromUtf8("menuFiltros"));
        menuUndo = new QMenu(menubar);
        menuUndo->setObjectName(QString::fromUtf8("menuUndo"));
        menuRedo = new QMenu(menubar);
        menuRedo->setObjectName(QString::fromUtf8("menuRedo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuCartuchera->menuAction());
        menubar->addAction(menuCaracter_sticas->menuAction());
        menubar->addAction(menuFiguras->menuAction());
        menubar->addAction(menuPintar->menuAction());
        menubar->addAction(menuFiltros->menuAction());
        menubar->addAction(menuUndo->menuAction());
        menubar->addAction(menuRedo->menuAction());
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(actionCargar_Imagen);
        menuArchivo->addAction(actionGuardar_Imagen);
        menuCartuchera->addAction(actionL_piz);
        menuCartuchera->addAction(actionLapicero);
        menuCartuchera->addAction(actionBorrador);
        menuCaracter_sticas->addAction(actionGrosor);
        menuCaracter_sticas->addAction(actionColor);
        menuFiguras->addAction(actionRect_ngulo);
        menuFiguras->addAction(actionTri_ngulo);
        menuFiguras->addAction(actionC_rculo);
        menuPintar->addAction(actionFill);
        menuPintar->addAction(actionColorPicker);
        menuFiltros->addAction(actionBlanco_y_negro);
        menuFiltros->addAction(actionNegativo);
        menuFiltros->addAction(actionIntercambio_de_azul_y_rojo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCargar_Imagen->setText(QApplication::translate("MainWindow", "Cargar Imagen", nullptr));
        actionGuardar_Imagen->setText(QApplication::translate("MainWindow", "Guardar Imagen", nullptr));
        actionL_piz->setText(QApplication::translate("MainWindow", "L\303\241piz", nullptr));
        actionLapicero->setText(QApplication::translate("MainWindow", "Lapicero", nullptr));
        actionBorrador->setText(QApplication::translate("MainWindow", "Borrador", nullptr));
        actionGrosor->setText(QApplication::translate("MainWindow", "Grosor", nullptr));
        actionColor->setText(QApplication::translate("MainWindow", "Color", nullptr));
        actionRect_ngulo->setText(QApplication::translate("MainWindow", "Rect\303\241ngulo", nullptr));
        actionTri_ngulo->setText(QApplication::translate("MainWindow", "Tri\303\241ngulo", nullptr));
        actionC_rculo->setText(QApplication::translate("MainWindow", "C\303\255rculo", nullptr));
        actionFill->setText(QApplication::translate("MainWindow", "Fill", nullptr));
        actionColorPicker->setText(QApplication::translate("MainWindow", "ColorPicker", nullptr));
        actionBlanco_y_negro->setText(QApplication::translate("MainWindow", "Blanco y negro", nullptr));
        actionNegativo->setText(QApplication::translate("MainWindow", "Negativo", nullptr));
        actionNuevo->setText(QApplication::translate("MainWindow", "Nuevo", nullptr));
        actionIntercambio_de_azul_y_rojo->setText(QApplication::translate("MainWindow", "Intercambio de azul y rojo", nullptr));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuCartuchera->setTitle(QApplication::translate("MainWindow", "Cartuchera", nullptr));
        menuCaracter_sticas->setTitle(QApplication::translate("MainWindow", "Caracter\303\255sticas", nullptr));
        menuFiguras->setTitle(QApplication::translate("MainWindow", "Figuras", nullptr));
        menuPintar->setTitle(QApplication::translate("MainWindow", "Pintar", nullptr));
        menuFiltros->setTitle(QApplication::translate("MainWindow", "Filtros", nullptr));
        menuUndo->setTitle(QApplication::translate("MainWindow", "Undo", nullptr));
        menuRedo->setTitle(QApplication::translate("MainWindow", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
