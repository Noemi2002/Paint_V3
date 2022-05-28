/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *cargarImagen;
    QPushButton *lapizButton;
    QPushButton *lapiceroButton;
    QPushButton *borradorButton;
    QPushButton *guardarButton;
    QPushButton *colorBUtton;
    QPushButton *grosorButton;
    QGraphicsView *canva;
    QPushButton *linea;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1229, 600);
        cargarImagen = new QPushButton(Widget);
        cargarImagen->setObjectName(QString::fromUtf8("cargarImagen"));
        cargarImagen->setGeometry(QRect(20, 10, 111, 25));
        lapizButton = new QPushButton(Widget);
        lapizButton->setObjectName(QString::fromUtf8("lapizButton"));
        lapizButton->setGeometry(QRect(20, 100, 111, 25));
        lapiceroButton = new QPushButton(Widget);
        lapiceroButton->setObjectName(QString::fromUtf8("lapiceroButton"));
        lapiceroButton->setGeometry(QRect(20, 130, 111, 25));
        borradorButton = new QPushButton(Widget);
        borradorButton->setObjectName(QString::fromUtf8("borradorButton"));
        borradorButton->setGeometry(QRect(20, 160, 111, 25));
        guardarButton = new QPushButton(Widget);
        guardarButton->setObjectName(QString::fromUtf8("guardarButton"));
        guardarButton->setGeometry(QRect(20, 40, 111, 25));
        colorBUtton = new QPushButton(Widget);
        colorBUtton->setObjectName(QString::fromUtf8("colorBUtton"));
        colorBUtton->setGeometry(QRect(20, 190, 111, 25));
        grosorButton = new QPushButton(Widget);
        grosorButton->setObjectName(QString::fromUtf8("grosorButton"));
        grosorButton->setGeometry(QRect(20, 220, 111, 25));
        canva = new QGraphicsView(Widget);
        canva->setObjectName(QString::fromUtf8("canva"));
        canva->setGeometry(QRect(170, 40, 1041, 541));
        linea = new QPushButton(Widget);
        linea->setObjectName(QString::fromUtf8("linea"));
        linea->setGeometry(QRect(30, 270, 89, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        cargarImagen->setText(QApplication::translate("Widget", "Cargar Imagen", nullptr));
        lapizButton->setText(QApplication::translate("Widget", "L\303\241piz", nullptr));
        lapiceroButton->setText(QApplication::translate("Widget", "Lapicero", nullptr));
        borradorButton->setText(QApplication::translate("Widget", "Borrador", nullptr));
        guardarButton->setText(QApplication::translate("Widget", "Guardar", nullptr));
        colorBUtton->setText(QApplication::translate("Widget", "Color", nullptr));
        grosorButton->setText(QApplication::translate("Widget", "Grosor", nullptr));
        linea->setText(QApplication::translate("Widget", "linea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
