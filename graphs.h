#ifndef GRAPHS_H
#define GRAPHS_H

#include <QWidget>
#include <QVector>
#include <QTime>

namespace Ui {
class graphs;
}

class graphs : public QWidget
{
    Q_OBJECT
private:
    double start;

public:
    explicit graphs(QVector<QVector<int>> data,QWidget *parent = nullptr);
    ~graphs();
signals:
    //void clearD();
private slots:
    void newData(QVector<int> data);


private:
    Ui::graphs *ui;
};

#endif // GRAPHS_H
