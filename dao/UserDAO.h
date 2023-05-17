//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_USERDAO_H
#define EXERCICE07_LIBRARY_USERDAO_H


#include "../entity/User.h"
#include "BaseDAO.h"

class UserDAO : public BaseDAO<User> {
public:
    UserDAO(QSqlDatabase& db) : BaseDAO<User>(db) {UserDAO::init();}
    void init() override;
    bool add(User& log) override;
    bool remove(const int id) override;
    QList<User> getAll() override;
    User get(const int id) override;

};


#endif //EXERCICE07_LIBRARY_USERDAO_H
