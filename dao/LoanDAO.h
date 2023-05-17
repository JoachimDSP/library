//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_LOANDAO_H
#define EXERCICE07_LIBRARY_LOANDAO_H


#include <QSqlDatabase>
#include "../entity/Loan.h"
#include "BaseDAO.h"

class LoanDAO : public BaseDAO<Loan> {
public:
    LoanDAO(QSqlDatabase& db) : BaseDAO<Loan>(db) {LoanDAO::init();}
    void init() override;
    bool add(Loan& loan) override;
    bool remove(const int id) override;
    QList<Loan> getAll() override;
    Loan get(const int id) override;

};



#endif //EXERCICE07_LIBRARY_LOANDAO_H
