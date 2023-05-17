#include <QApplication>
#include <QPushButton>
#include <QDir>

#include "dao/BaseDAO.h"
#include "dao/BookDAO.h"
#include "dao/LoanDAO.h"
#include "dao/LogDAO.h"
#include "dao/UserDAO.h"
#include "entity/Book.h"
#include "entity/Loan.h"
#include "entity/Log.h"
#include "entity/User.h"
#include "widget/bookwidget.h"
#include "widget/userwidget.h"
#include "window/loanwindow.h"
#include "window/returningwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString dataFolderPath = QCoreApplication::applicationDirPath() + "/data";
    QDir().mkpath(dataFolderPath);

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(dataFolderPath + "/demo.db");

    UserDAO userDao(database);
    BookDAO bookDao(database);

    LoanWindow loanWindow(database, userDao, bookDao);
    loanWindow.show();
    return QApplication::exec();
}
