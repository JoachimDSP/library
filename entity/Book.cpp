//
// Created by Administrateur on 17/05/2023.
//

#include "Book.h"

Book::Book(const int id, const QString& isbn, const QString& title, const int edition, const QString& publisher, const int copyright, const double price, const QString&  author): p_id(id), p_isbn(isbn), p_title(title), p_edition(edition), p_publisher(publisher), p_copyright(copyright), p_price(price), p_author(author){}

int Book::getId() const {
    return this->p_id;
}

QString Book::getIsbn() const {
    return this->p_isbn;
}

QString Book::getTitle() const {
    return this->p_title;
}

int Book::getEdition() const {
    return this->p_edition;
}

QString Book::getPublisher() const {
    return this->p_publisher;
}

int Book::getCopyright() const {
    return this->p_copyright;
}

double Book::getPrice() const {
    return this->p_price;
}

QString Book::getAuthor() const {
    return this->p_author;
}

void Book::setId(const int id) {
    this->p_id = id;
}