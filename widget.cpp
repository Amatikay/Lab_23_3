#include "widget.h"
#include "./ui_widget.h"
#include "dbmanager.h"
#include "printgraph.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_OpenFieleObserver_pushButton_clicked(){
      QString path_to_file = QFileDialog::getOpenFileName();
      DbManager *Db = new DbManager(path_to_file);
      PrintGraph *pG  = new PrintGraph(*Db);
      ui->verticalLayout_2->addWidget(pG->chartView);// при сузествуюзей реадизации скроее всего прсото буду открывать новой окно для графика.
}
void Widget::on_Print_pushButton_clicked(){

}

void Widget::on_SelectFolderToSavePdf_pushButton_clicked(){

}
void Widget::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint){

}
