#include "graphs.h"
#include "ui_graphs.h"

graphs::graphs(QVector<QVector<int>> data,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphs)
{
    ui->setupUi(this);
    int max = data.size();
    start = QDateTime::currentDateTime().toTime_t();
    QVector<double> xacc(max), yacc(max), zacc(max), t(max);
    for (int i=0; i<max; i++)
    {
        xacc[i] = (double)(data[i][0] * 2)/INT16_MAX;
        yacc[i] = (double)(data[i][1] * 2)/INT16_MAX;
        zacc[i] = (double)(data[i][2] * 2)/INT16_MAX;
        t[i] = start-((max-i)*0.1667);
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(t,xacc);
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(0)->setName("Wskazania osi x");
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(t,yacc);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(1)->setName("Wskazania osi y");
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setData(t,zacc);
    ui->customPlot->graph(2)->setPen(QPen(Qt::green));
    ui->customPlot->graph(2)->setName("Wskazania osi z");
    ui->customPlot->yAxis->setRange(-1.5, 1.5);
    ui->customPlot->xAxis->setRange(start-((max)*0.1667), start);
    start = start-((max)*0.1667);
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss");
    ui->customPlot->xAxis->setTicker(dateTicker);
    ui->customPlot->xAxis->setLabel("Czas [hh:mm:ss]");
    ui->customPlot->yAxis->setLabel("Przyspieszenie [g]");
    ui->customPlot->legend->setVisible(true);
    //ui->customPlot->legend->setBrush(QColor(255, 255, 255, 150));
  }

  graphs::~graphs()
  {
      //emit clearD();
      delete ui;
  }

  void graphs::newData(QVector<int> data){
      double t = QDateTime::currentDateTime().toTime_t();
      for (int i=0; i<3; i++)
      {
          ui->customPlot->graph(i)->addData(t,(double)(data[i] * 2)/INT16_MAX);
      }
      ui->customPlot->yAxis->setRange(-1.5, 1.5);
      ui->customPlot->xAxis->setRange(start,t);
      if(start<QDateTime::currentDateTime().addSecs(-90).toTime_t()){
        ui->customPlot->xAxis->setRange(QDateTime::currentDateTime().addSecs(-90).toTime_t(),t);
      }
      ui->customPlot->replot();
  }
