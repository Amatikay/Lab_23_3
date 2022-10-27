#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QDebug> //для отладки, но какая из библиотек нужна пока не понятно
#include <QtDebug> //
#include <QtWidgets>
#include <QWidget>
#include <cstdio>
#include <cstdlib>

#include <QTableView>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void on_OpenFieleObserver_pushButton_clicked(); // открывалка фалового обозревателя
    void on_SelectFolderToSavePdf_pushButton_clicked();//выбор папки для сохрениния пдф
    void on_Print_pushButton_clicked();//печать
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
