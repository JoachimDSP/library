//
// Created by Administrateur on 17/05/2023.
//

#include <QList>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include "LoanDAO.h"

void LoanDAO::init() {
    p_db.open();
    if(!p_db.tables().contains("loan")) {
        p_query = new QSqlQuery(p_db);
        bool result = p_query->exec("CREATE TABLE book (id INTEGER PRIMARY KEY, bookId INT, userId INT)");
        if(!result) {
            p_error = p_query->lastError();
            qDebug() << p_error.text();
        }
    }
    p_db.close();
}

bool LoanDAO::add(Loan& loan) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("INSERT INTO loan (bookId, userId) values (:bookId, :userId)");
    p_query->bindValue(":bookId", loan.getBookId());
    p_query->bindValue(":userId", loan.getUserId());
    bool result = p_query->exec();
    QVariant id = p_query->lastInsertId();
    if(id.isValid()) {
        loan.setId(id.toInt());
    }
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

bool LoanDAO::remove(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("DELETE FROM loan where id = :id");
    p_query->bindValue(":id", id);
    bool result = p_query->exec();
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

QList<Loan> LoanDAO::getAll() {
    QList<Loan> loans;
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->exec("SELECT * FROM loan");
    while(p_query->next()) {
        loans.append(Loan(p_query->value("id").toInt(),p_query->value("bookId").toInt(), p_query->value("UserId").toInt() ));
    }
    p_db.close();
    return loans;
}

Loan LoanDAO::get(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("SELECT * FROM loan where id = :id");
    p_query->bindValue(":id", id);
    if(p_query->next()) {
        return  Loan(p_query->value("id").toInt(),p_query->value("bookId").toInt(), p_query->value("UserId").toInt() );
    }
    else {
        return Loan();
    }
}
