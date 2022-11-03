//
// Created by sergey on 02.11.22.
//

#ifndef LAB_23_3_PRINTHIST_H
#define LAB_23_3_PRINTHIST_H


#include "graph.h"
#include "dbmanager.h"
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QBarCategoryAxis>
#include <QChartView>

class printHist:public Graph {
public:
    printHist();
    explicit printHist(const DbManager& Db);
    QtCharts::QChartView *chartView;
    ~printHist();
private:
    QtCharts::QBarSet *dataSet;
    QtCharts::QBarSeries *series;
    QtCharts::QChart *chart;
    QtCharts::QChart::AnimationOptions SeriesAnimations;
    QtCharts::QBarCategoryAxis *axisX;
    QtCharts::QValueAxis *axisY;
};
#endif //LAB_23_3_PRINTHIST_H
