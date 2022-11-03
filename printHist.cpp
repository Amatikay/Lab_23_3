//
// Created by sergey on 02.11.22.
//

#include "printHist.h"

printHist::~printHist() {
    delete dataSet;
    delete series;
    delete chart;
    delete axisX;
    delete axisY;
    delete chartView;
}

printHist::printHist(const DbManager &Db) : dataSet(nullptr) {
    dataSet = new QtCharts::QBarSet("Histogram from " + Db.tableName);
    int i =0;
    foreach (QString key, Db.map.keys()){
            if (i>3){
                break;
            }
            i++;
        int value=Db.map.value(key);
        *dataSet << value;
    }
    series = new QtCharts::QBarSeries();
    series->append(dataSet);
    chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle(Db.tableName);
    chart->setAnimationOptions(SeriesAnimations);
    QStringList category;
    category << "date";
    axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(category);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY = new QtCharts::QValueAxis();
    axisY->setRange(0,15);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}
