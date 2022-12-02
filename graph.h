#ifndef GRAPH_H
#define GRAPH_H


#include <QLineSeries>
#include <QChart>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QChartView>

class Graph
{
public:
     ~Graph();
    QtCharts::QChartView *chartView;
protected:
    QtCharts::QChart *chart;
    QtCharts::QValueAxis *axisY;
};

#endif // GRAPH_H
