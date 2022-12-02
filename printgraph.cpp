#include "printgraph.h"

PrintGraph::PrintGraph()
{

}
PrintGraph::PrintGraph(const QMap<QString,float> &map,const QString &tableName)
{
    series = new QtCharts::QLineSeries();
    int i = 0; // "Костыль" для того, чтобы отображать не все данные в графике. Иначе он первращается в кашу.
    foreach (QString key, map.keys()){ //проходимя по всем элементам мапа (ключ:значение)
       if (i>1){
           break;
       }
       i++;
        int value=map.value(key);

        QDateTime momentInTime = QDateTime::fromString(key,"dd.MM.yyyy hh:mm");
        series->append(momentInTime.toMSecsSinceEpoch(),value);
    }

    chart = new QtCharts::QChart();

    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Line Plot for Database: "+ tableName);

    axisX = new QtCharts::QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("dd.MM.yyyy hh:mm");
    axisX->setTitleText("Time");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QtCharts::QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Value");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
 }

PrintGraph::~PrintGraph() {
//    delete chartView;
    delete series;
//    delete chart;
    delete axisX;
//    delete axisY;
}
