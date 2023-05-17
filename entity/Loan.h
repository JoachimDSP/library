//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_LOAN_H
#define EXERCICE07_LIBRARY_LOAN_H


class Loan {
private:
    int p_id;
    int p_bookId;
    int p_userId;

public:
    Loan() = default;
    Loan(const int id, const int bookId, const int userId);
    int getId() const;
    int getBookId() const;
    int getUserId() const;
    void setId(const int id);

};

//bonjour
#endif //EXERCICE07_LIBRARY_LOAN_H
