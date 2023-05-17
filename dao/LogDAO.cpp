//
// Created by Administrateur on 17/05/2023.
//

#include <QList>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include "LogDAO.h"

void LogDAO::init() {
    p_db.open();
    if(!p_db.tables().contains("log")) {
        p_query = new QSqlQuery(p_db);
        bool result = p_query->exec("CREATE TABLE log (id INTEGER PRIMARY KEY, bookId INT, userId INT, logDate TEXT)");
        if(!result) {
            p_error = p_query->lastError();
            qDebug() << p_error.text();
        }
    }
    p_db.close();
}

bool LogDAO::add(Log& log) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("INSERT INTO log (bookId, userId, logDate) values (:bookId, :userId, :logDate)");
    p_query->bindValue(":bookId", log.getBookId());
    p_query->bindValue(":userId", log.getUserId());
    p_query->bindValue(":logDate", log.getLogDate());
    bool result = p_query->exec();
    QVariant id = p_query->lastInsertId();
    if(id.isValid()) {
        log.setId(id.toInt());
    }
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

bool LogDAO::remove(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("DELETE FROM log where id = :id");
    p_query->bindValue(":id", id);
    bool result = p_query->exec();
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

QList<Log> LogDAO::getAll() {
    QList<Log> logs;
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->exec("SELECT * FROM log");
    while(p_query->next()) {
        logs.append(Log(p_query->value("id").toInt(),p_query->value("bookId").toInt(), p_query->value("UserId").toInt(), p_query->value("logDate").toString() ));
    }
    p_db.close();
    return logs;
}

Log LogDAO::get(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("SELECT * FROM log where id = :id");
    p_query->bindValue(":id", id);
    if(p_query->next()) {
        return  Log(p_query->value("id").toInt(),p_query->value("bookId").toInt(), p_query->value("UserId").toInt(), p_query->value("logDate").toString() );
    }
    else {
        return Log();
    }
}
