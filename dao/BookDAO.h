//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_BOOKDAO_H
#define EXERCICE07_LIBRARY_BOOKDAO_H

#include <QSqlDatabase>
#include "../entity/Book.h"
#include "BaseDAO.h"

class BookDAO : public BaseDAO<Book> {

public:
    BookDAO(QSqlDatabase& db) : BaseDAO<Book>(db) {BookDAO::init();}
    void init() override;
    bool add(Book& book) override;
    bool remove(const int id) override;
    QList<Book> getAll() override;
    Book get(const int id) override;
    QList<Book> getAllAvailables();
};


#endif //EXERCICE07_LIBRARY_BOOKDAO_H
