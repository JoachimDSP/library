//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_LOG_H
#define EXERCICE07_LIBRARY_LOG_H


#include <QString>

class Log {
private:
    int p_id;
    int p_bookId;
    int p_userId;
    QString p_logDate;

public:
    Log() = default;
    Log(const int id, const int bookId, const int userId, const QString logDate);
    int getId() const;
    int getBookId() const;
    int getUserId() const;
    QString getLogDate() const;
    void setId(const int id);

};


#endif //EXERCICE07_LIBRARY_LOG_H
