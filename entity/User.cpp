//
// Created by Administrateur on 17/05/2023.
//

#include "User.h"

User::User(const int id, const QString name, const QString email) {
    p_id = id;
    p_name = name;
    p_email = email;
}

int User::getId() const {
    return p_id;
}

QString User::getEmail() const {
    return p_email;
}

QString User::getName() const {
    return p_name;
}

void User::setId(const int id) {
    p_id = id;
}