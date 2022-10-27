#include "dbmanager.h"



DbManager::DbManager(const QString& path)
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (!m_db.open())
   {
      qDebug() << m_db.lastError().text();// Должно быть так, но я не раборался с дебагером в qt  по этому добалю 2 строки ниже
      QTextStream out(stdout);
      out << m_db.lastError().text() << Qt::endl;
   }
   else
   {
      qDebug() << "Database: connection ok";
      QTextStream out(stdout);
      out << "Database: connection ok" << Qt::endl;
   }
}
