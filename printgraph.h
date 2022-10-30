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
    PrintGraph(const DbManager& Db);
    void saveAsPdf();
    QtCharts::QChartView *chartView;
};

#endif // PRINTGRAPH_H
