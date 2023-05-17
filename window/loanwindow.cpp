//
// Created by Administrateur on 17/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoanWindow.h" resolved

#include "loanwindow.h"
#include "ui_LoanWindow.h"


LoanWindow::LoanWindow(QSqlDatabase& db, UserDAO& userDao, BookDAO& bookDao, QWidget *parent) : QMainWindow(parent), ui(new Ui::LoanWindow) {
    p_db = &db;
    p_userDao = &userDao;
    p_bookDao = &bookDao;
    ui->setupUi(this);
    createContent();
}

LoanWindow::~LoanWindow() {
    delete ui;
}

void LoanWindow::createContent() {
    VLayout = new QVBoxLayout(this);
    HLayout = new QHBoxLayout(this);
    lbl_user = new QLabel("Users", this);
    lbl_book = new QLabel("Books", this);
    cb_user = new QComboBox(this);
    cb_book = new QComboBox(this);
    btn_valid = new QPushButton("BORROW", this);

    QList<User> usersList = p_userDao->getAll();
    for (int i = 0; i < usersList.size(); i++) {
        cb_user->addItem(usersList[i].getName());
    }

    QList<Book> booksList = p_bookDao->getAllAvailables();
    for (int i = 0; i < booksList.size(); i++) {
        cb_book->addItem(booksList[i].getTitle());
    }

    HLayout->addWidget(lbl_user);
    HLayout->addWidget(cb_user);
    HLayout->addWidget(lbl_book);
    HLayout->addWidget(cb_book);
    VLayout->addLayout(HLayout);
    VLayout->addWidget(btn_valid);

    QObject::connect(btn_valid, &QPushButton::clicked, this, &LoanWindow::bookBorrowed);
}

void LoanWindow::bookBorrowed() {
    qDebug() << "Un livre a été emprunté.";
}