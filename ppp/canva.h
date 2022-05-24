#ifndef CANVA_H
#define CANVA_H

#include <QWidget>

class Canva : public QWidget
{
    Q_OBJECT
public:
    explicit Canva(QWidget *parent = nullptr);

private:
    void print();

signals:

};

#endif // CANVA_H
