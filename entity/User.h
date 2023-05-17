//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_USER_H
#define EXERCICE07_LIBRARY_USER_H


#include <QString>

class User {
private:
    int p_id;
    QString p_name;
    QString p_email;

public:
    User() = default;
    User(const int id, const QString name, const QString email);
    int getId() const;
    QString getName() const;
    QString getEmail() const;
    void setId(const int id);

};


#endif //EXERCICE07_LIBRARY_USER_H
