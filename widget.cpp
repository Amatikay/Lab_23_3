#include "widget.h"
#include "./ui_widget.h"
#include "dbmanager.h"
#include "printgraph.h"
#include "printHist.h"


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
    DbManager Db(path_to_file);

    switch(ui->TypeChart_comboBox->currentIndex()) {
        case 0 : {
            pG = new PrintGraph(Db.returnMap(),Db.returnTableName());
            ui->verticalLayout_2->addWidget(pG->chartView);// при существующей реализации скорее всего просто буду открывать новой окно для графика.
        }
        case 1 : {
             pH = new printHist(Db.returnMap(),Db.returnTableName());
            ui->verticalLayout_2->addWidget(pH->chartView);
        }
    }

}
void Widget::on_clear_pushButton_clicked(){
    switch (ui->verticalLayout_2->isEmpty()){
        case 0: {
            ui->verticalLayout_2->removeWidget(pG->chartView);
            ui->verticalLayout_2->removeWidget(pH->chartView);
        }
        case 1:{
            qDebug() << "Empty!";
        }
    }
    //ui->verticalLayout_2->removeWidget();
}

//void Widget::on_SelectFolderToSavePdf_pushButton_clicked(){
//
//}
//void Widget::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint){
//
//}
