//
// Created by Administrateur on 17/05/2023.
//

#include "Loan.h"

Loan::Loan(const int id, const int bookId, const int userId) : p_id(id), p_bookId(bookId), p_userId(userId) {}

int Loan::getId() const {
    return this->p_id;
}

int Loan::getBookId() const {
    return this->p_bookId;
}

int Loan::getUserId() const {
    return this->p_userId;
}

void Loan::setId(const int id) {
    this->p_id = id;
}