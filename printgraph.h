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
    //explicit PrintGraph(const DbManager& Db);//переделываю
    explicit PrintGraph(const QMap<QString,float> &map,const QString &tableName);
    void saveAsPdf();

    ~PrintGraph();
private:
    QtCharts::QLineSeries *series;
    QtCharts::QDateTimeAxis *axisX;
};

#endif // PRINTGRAPH_H
