//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_LOANWINDOW_H
#define EXERCICE07_LIBRARY_LOANWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>

#include "../dao/BookDAO.h"
#include "../dao/UserDAO.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoanWindow; }
QT_END_NAMESPACE

class LoanWindow : public QMainWindow {
Q_OBJECT

public:
    explicit LoanWindow(QSqlDatabase& db, UserDAO& userDao, BookDAO& bookDao, QWidget *parent = nullptr);

    ~LoanWindow() override;

private:
    Ui::LoanWindow *ui;
    QSqlDatabase* p_db;
    UserDAO* p_userDao;
    BookDAO* p_bookDao;
    QMenu* menu;
    QWidget* p_mainWidget;
    QVBoxLayout* VLayout;
    QHBoxLayout* HLayout;
    QLabel* lbl_user;
    QLabel* lbl_book;
    QComboBox* cb_user;
    QComboBox* cb_book;
    QPushButton* btn_valid;

    void createContent();

private slots:
    void bookBorrowed();


};


#endif //EXERCICE07_LIBRARY_LOANWINDOW_H
