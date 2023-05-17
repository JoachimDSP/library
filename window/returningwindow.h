//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_RETURNINGWINDOW_H
#define EXERCICE07_LIBRARY_RETURNINGWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ReturningWindow; }
QT_END_NAMESPACE

class ReturningWindow : public QWidget {
Q_OBJECT

public:
    explicit ReturningWindow(QWidget *parent = nullptr);

    ~ReturningWindow() override;

private:
    Ui::ReturningWindow *ui;
};


#endif //EXERCICE07_LIBRARY_RETURNINGWINDOW_H
