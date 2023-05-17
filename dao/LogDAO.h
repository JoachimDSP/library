//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_LOGDAO_H
#define EXERCICE07_LIBRARY_LOGDAO_H


#include <QSqlDatabase>
#include "../entity/Log.h"
#include "BaseDAO.h"

class LogDAO : public BaseDAO<Log> {
public:
    LogDAO(QSqlDatabase& db) : BaseDAO<Log>(db) {LogDAO::init();}
    void init() override;
    bool add(Log& log) override;
    bool remove(const int id) override;
    QList<Log> getAll() override;
    Log get(const int id) override;

};


#endif //EXERCICE07_LIBRARY_LOGDAO_H
