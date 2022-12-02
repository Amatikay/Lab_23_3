#include "dbmanager.h"
#include <iostream>


DbManager::DbManager(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE","DataBase_Openend_in_Db_Manager");
   m_db.setDatabaseName(path);
   this->path=path;

   if (!m_db.open())
   {
      qDebug() << m_db.lastError().text();// Должно быть так, но я не разобрался с дебагером в qt  по этому добавлю 2 строки ниже
//      QTextStream out(stdout);
//      out << m_db.lastError().text() << Qt::endl;
   }
   else
   {
      qDebug() << "Database: connection ok";
//      QTextStream out(stdout);
//      out << "Database: connection ok\n" << path << Qt::endl;
   }
   QFileInfo file(path);
   QString fileName = file.baseName();
   tableName=fileName;
   QSqlQuery query(m_db);

   if (!query.exec("SELECT * FROM " + tableName))
   {
       qDebug() << m_db.lastError().text();
       // отловить ошибку
   }
   while(query.next()){
       map.insert(query.value(0).toString(), query.value(1).toFloat());
   }
}
DbManager::~DbManager() {

    m_db.close();
    QSqlDatabase::removeDatabase("DataBase_Openend_in_Db_Manager");
}