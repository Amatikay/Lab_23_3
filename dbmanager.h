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
    explicit DbManager(const QString& path);
    ~DbManager();
    QMap<QString,float> returnMap(){return this->map;};
    QString returnTableName(){return this->tableName;}
    // Вообще обращение к данным через Db->map. Нужен ли метод для выдачи, или мап может оставаться публичным?TODO нужен
   // QString showName(){return tableName;}; разобраться что не так

private:
    QSqlDatabase m_db;
    QString path;
    QMap<QString,float> map;
   QString tableName;

};

#endif // DBMANAGER_H
