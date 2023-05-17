//
// Created by Administrateur on 17/05/2023.
//

#include <QList>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include "UserDAO.h"

void UserDAO::init() {
    p_db.open();
    if(!p_db.tables().contains("user")) {
        p_query = new QSqlQuery(p_db);
        bool result = p_query->exec("CREATE TABLE user (id INTEGER PRIMARY KEY, name TEXT, email TEXT)");
        if(!result) {
            p_error = p_query->lastError();
            qDebug() << p_error.text();
        }
    }
    p_db.close();
}

bool UserDAO::add(User& user) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("INSERT INTO user (name, email) values (:name, :email)");
    p_query->bindValue(":name", user.getName());
    p_query->bindValue(":email", user.getEmail());
    bool result = p_query->exec();
    QVariant id = p_query->lastInsertId();
    if(id.isValid()) {
        user.setId(id.toInt());
    }
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

bool UserDAO::remove(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("DELETE FROM user where id = :id");
    p_query->bindValue(":id", id);
    bool result = p_query->exec();
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

QList<User> UserDAO::getAll() {
    QList<User> users;
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->exec("SELECT * FROM user");
    while(p_query->next()) {
        users.append(User(p_query->value("id").toInt(), p_query->value("name").toString(), p_query->value("email").toString() ));
    }
    p_db.close();
    return users;
}

User UserDAO::get(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("SELECT * FROM log where id = :id");
    p_query->bindValue(":id", id);
    if(p_query->next()) {
        return  User(p_query->value("id").toInt(), p_query->value("name").toString(), p_query->value("email").toString() );
    }
    else {
        return User();
    }
}