//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_BASEDAO_H
#define EXERCICE07_LIBRARY_BASEDAO_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

template <typename T>
class BaseDAO {

public:
    BaseDAO(QSqlDatabase& db):p_db(db) {

    }
    virtual void init()  = 0;
    virtual bool add(T& contact) = 0;
    virtual bool remove(const int id) = 0;
    virtual QList<T> getAll() = 0;
    virtual T get(const int id) = 0;

    virtual ~BaseDAO() = default;

protected:
    QSqlDatabase& p_db;
    QSqlQuery* p_query;
    QSqlError p_error;
};


#endif //EXERCICE07_LIBRARY_BASEDAO_H
