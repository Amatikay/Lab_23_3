#include "widget.h"
#include <QApplication>

#include <QtSql>
#include <QTableView>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "Application stertup";
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
