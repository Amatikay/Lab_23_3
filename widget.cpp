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
    DbManager *Db = new DbManager(path_to_file);

    switch(ui->TypeChart_comboBox->currentIndex()) {
        case 0 : {
            pG = new PrintGraph(*Db);
            ui->verticalLayout_2->addWidget(pG->chartView);// при сузествуюзей реадизации скроее всего прсото буду открывать новой окно для графика.
        }
        case 1 : {
             pH = new printHist(*Db);
            ui->verticalLayout_2->addWidget(pH->chartView);
        }
    }
}
void Widget::on_clear_pushButton_clicked(){
    switch (ui->verticalLayout_2->isEmpty()){
        case 0: {
            ui->verticalLayout_2->removeWidget(pG->chartView);
        }
        case 1:{
            qDebug() << "Empty!";
            \
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
