//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_BOOK_H
#define EXERCICE07_LIBRARY_BOOK_H

#include <QString>


class Book {

public:
    Book() = default;
    Book(const int id, const QString& isbn, const QString& title, const int edition, const QString& publisher, const int copyright, const double price, const QString&  author);


    int getId() const;
    QString getIsbn() const;
    QString getTitle() const;
    int getEdition() const;
    QString getPublisher() const;
    int getCopyright() const;
    double getPrice() const;
    QString getAuthor() const;

    void setId(const int id);

private:

    int p_id;
    QString p_isbn;
    QString p_title;
    int p_edition;
    QString p_publisher;
    int p_copyright;
    double p_price;
    QString p_author;

};


#endif //EXERCICE07_LIBRARY_BOOK_H
