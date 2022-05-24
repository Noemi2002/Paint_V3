#ifndef CANVA_H
#define CANVA_H

#include <QMainWindow>

class canva : public QMainWindow
{
    Q_OBJECT
public:
    explicit canva(QWidget *parent = nullptr);

private:
    void print();

signals:

};

#endif // CANVA_H
