//
// Created by Administrateur on 17/05/2023.
//

#include <QList>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include "BookDAO.h"

void BookDAO::init() {
    p_db.open();
    if(!p_db.tables().contains("book")) {
        p_query = new QSqlQuery(p_db);
        bool result = p_query->exec("CREATE TABLE book (id INTEGER PRIMARY KEY, isbn TEXT, title TEXT, edition INT, publisher TEXT, copyright INT, price REAL, authors TEXT)");
        if(!result) {
            p_error = p_query->lastError();
            qDebug() << p_error.text();
        }
    }
    p_db.close();
}

bool BookDAO::add(Book& book) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("INSERT INTO book (isbn, title, edition, publisher, copyright, price, authors) values (:isbn, :title, :edition, :publisher, :copyright, :price, :authors)");
    p_query->bindValue(":isbn", book.getIsbn());
    p_query->bindValue(":title", book.getTitle());
    p_query->bindValue(":edition", book.getEdition());
    p_query->bindValue(":publisher", book.getPublisher());
    p_query->bindValue(":copyright", book.getCopyright());
    p_query->bindValue(":price", book.getPrice());
    p_query->bindValue(":authors", book.getAuthor());
    bool result = p_query->exec();
    QVariant id = p_query->lastInsertId();
    if(id.isValid()) {
        book.setId(id.toInt());
    }
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

bool BookDAO::remove(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("DELETE FROM book where id = :id");
    p_query->bindValue(":id", id);
    bool result = p_query->exec();
    if(!result) {
        p_error = p_query->lastError();
        qDebug() << p_error.text();
    }
    p_db.close();
    return result;
}

QList<Book> BookDAO::getAll() {
    QList<Book> books;
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->exec("SELECT * FROM book");
    while(p_query->next()) {
        books.append(Book(p_query->value("id").toInt(),p_query->value("isbn").toString(), p_query->value("title").toString(), p_query->value("edition").toInt(), p_query->value("publisher").toString(), p_query->value("copyright").toInt(), p_query->value("price").toDouble(), p_query->value("authors").toString() ));
    }
    p_db.close();
    return books;
}

QList<Book> BookDAO::getAllAvailables() {
    QList<Book> books;

    return books;
}

Book BookDAO::get(const int id) {
    p_db.open();
    p_query = new QSqlQuery(p_db);
    p_query->prepare("SELECT * FROM book where id = :id");
    p_query->bindValue(":id", id);
    if(p_query->next()) {
        return  Book(p_query->value("id").toInt(),p_query->value("isbn").toString(), p_query->value("title").toString(), p_query->value("edition").toInt(), p_query->value("publisher").toString(), p_query->value("copyright").toInt(), p_query->value("price").toDouble(), p_query->value("authors").toString());
    }
    else {
        return Book();
    }
}