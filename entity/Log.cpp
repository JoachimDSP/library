//
// Created by Administrateur on 17/05/2023.
//

#include "Log.h"

Log::Log(const int id, const int bookId, const int userId, const QString logDate) {
    p_id = id;
    p_bookId = bookId;
    p_userId = userId;
    p_logDate = logDate;
}

int Log::getId() const {
    return p_id;
}

int Log::getBookId() const {
    return p_bookId;
}

int Log::getUserId() const {
    return p_userId;
}

QString Log::getLogDate() const {
    return p_logDate;
}

void Log::setId(const int id) {
    p_id = id;
}