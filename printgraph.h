#ifndef PRINTGRAPH_H
#define PRINTGRAPH_H

#include "graph.h"
#include <QLineSeries>
#include "dbmanager.h"
#include <QDateTimeAxis>
#include <QChart>
#include <QChartView>
#include <QLineSeries>

class PrintGraph : public Graph
{
public:
    PrintGraph();
    explicit PrintGraph(const DbManager& Db);
    void saveAsPdf();
    QtCharts::QChartView *chartView;
    ~PrintGraph();
private:
    QtCharts::QLineSeries *series;
    QtCharts::QChart *chart;
    QtCharts::QDateTimeAxis *axisX;
    QtCharts::QValueAxis *axisY;

};

#endif // PRINTGRAPH_H
