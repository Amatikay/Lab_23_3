#include "widget.h"
#include "./ui_widget.h"



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
    QTextStream out(stdout);
    out << path_to_file << Qt::endl;
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(path_to_file);
    if (!dbase.open()) {

    }
    float x=0,y=0;

}
void Widget::on_Print_pushButton_clicked(){
}

void Widget::on_SelectFolderToSavePdf_pushButton_clicked(){

}








