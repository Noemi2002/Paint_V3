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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *colorBUtton;
    QPushButton *borradorButton;
    QPushButton *guardarButton;
    QPushButton *grosorButton;
    QPushButton *lapizButton;
    QPushButton *cargarImagen;
    QPushButton *lapiceroButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1198, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        colorBUtton = new QPushButton(centralwidget);
        colorBUtton->setObjectName(QString::fromUtf8("colorBUtton"));
        colorBUtton->setGeometry(QRect(10, 190, 111, 25));
        borradorButton = new QPushButton(centralwidget);
        borradorButton->setObjectName(QString::fromUtf8("borradorButton"));
        borradorButton->setGeometry(QRect(10, 160, 111, 25));
        guardarButton = new QPushButton(centralwidget);
        guardarButton->setObjectName(QString::fromUtf8("guardarButton"));
        guardarButton->setGeometry(QRect(10, 40, 111, 25));
        grosorButton = new QPushButton(centralwidget);
        grosorButton->setObjectName(QString::fromUtf8("grosorButton"));
        grosorButton->setGeometry(QRect(10, 220, 111, 25));
        lapizButton = new QPushButton(centralwidget);
        lapizButton->setObjectName(QString::fromUtf8("lapizButton"));
        lapizButton->setGeometry(QRect(10, 100, 111, 25));
        cargarImagen = new QPushButton(centralwidget);
        cargarImagen->setObjectName(QString::fromUtf8("cargarImagen"));
        lapiceroButton = new QPushButton(centralwidget);
        lapiceroButton->setObjectName(QString::fromUtf8("lapiceroButton"));
        lapiceroButton->setGeometry(QRect(10, 130, 111, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1198, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        colorBUtton->setText(QApplication::translate("MainWindow", "Color", nullptr));
        borradorButton->setText(QApplication::translate("MainWindow", "Borrador", nullptr));
        guardarButton->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
        grosorButton->setText(QApplication::translate("MainWindow", "Grosor", nullptr));
        lapizButton->setText(QApplication::translate("MainWindow", "L\303\241piz", nullptr));
        cargarImagen->setText(QApplication::translate("MainWindow", "Cargar Imagen", nullptr));
        lapiceroButton->setText(QApplication::translate("MainWindow", "Lapicero", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
