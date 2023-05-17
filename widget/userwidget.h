//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_USERWIDGET_H
#define EXERCICE07_LIBRARY_USERWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class UserWidget; }
QT_END_NAMESPACE

class UserWidget : public QWidget {
Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = nullptr);

    ~UserWidget() override;

private:
    Ui::UserWidget *ui;
};


#endif //EXERCICE07_LIBRARY_USERWIDGET_H
