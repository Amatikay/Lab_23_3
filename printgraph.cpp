#include "printgraph.h"

PrintGraph::PrintGraph()
{

}
PrintGraph::PrintGraph(const DbManager& Db)
{


    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    int i = 0; // "Костыль" для того, чтобы отображать не все данные в графике. Иначе он первращается в кашу.
    foreach (QString key, Db.map.keys()){ //проходимя по всем элементам мапа (ключ:значение)
       if (i>3){
           break;
       }
       i++;
        int value=Db.map.value(key);

        QDateTime momentInTime = QDateTime::fromString(key,"dd.MM.yyyy hh:mm");
        series->append(momentInTime.toMSecsSinceEpoch(),value);
    }

    QtCharts::QChart *chart = new QtCharts::QChart();

    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Line Plot for Database: "+ Db.tableName);

    QtCharts::QDateTimeAxis *axisX = new QtCharts::QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("dd.MM.yyyy hh:mm");
    axisX->setTitleText("Time");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Value");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->chartView = chartView;

 }
