#ifndef CANVA_H
#define CANVA_H

#include <QMainWindow>

class Canva : public QMainWindow
{
    Q_OBJECT
public:
    explicit Canva(QWidget *parent = nullptr);
    bool guardarImagen(const QString &fileName);

signals:

};

#endif // CANVA_H
