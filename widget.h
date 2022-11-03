#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug>
#include <QtDebug>
#include <QtWidgets>
#include <QWidget>
#include <cstdio>
#include <cstdlib>
#include <QSqlTableModel>
#include <QTableView>
#include "printHist.h"
#include "printgraph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void on_OpenFieleObserver_pushButton_clicked(); // открывалка фалового обозревателя
    //void on_SelectFolderToSavePdf_pushButton_clicked();//выбор папки для сохрениния пдф
    //void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);
    void on_clear_pushButton_clicked();

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
    PrintGraph *pG;
    printHist *pH;
};
#endif // WIDGET_H
