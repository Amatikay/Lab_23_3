#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QtSql>
#include <QSqlTableModel>
#include <QDebug>
#include <QMap>
#include <QValueAxis>

class DbManager //Этот класс является менеджером баз данных.
                //Пусть он выгружает из базы данных данные в оперативку
                //и дальше передает структуру данных необходимую для
                //выбранного типа графика.
{
public:
    DbManager(const QString& path);
    ~DbManager(); // Память я не выделял по этому деструктор не прописываю. Компилятор сам все сделает
    QMap<QString,float> map;
    // Вообще обращение к данным черех Db->map. Нужен ли метод для выдачи, или мап может оставаться публичным?
   // QString showName(){return tableName;}; разобраться что не так
    QString tableName;
private:
    QSqlDatabase m_db;
    QString path;
   //QString tableName;

};

#endif // DBMANAGER_H
