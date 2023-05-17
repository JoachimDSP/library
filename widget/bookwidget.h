//
// Created by Administrateur on 17/05/2023.
//

#ifndef EXERCICE07_LIBRARY_BOOKWIDGET_H
#define EXERCICE07_LIBRARY_BOOKWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class BookWidget; }
QT_END_NAMESPACE

class BookWidget : public QWidget {
Q_OBJECT

public:
    explicit BookWidget(QWidget *parent = nullptr);

    ~BookWidget() override;

private:
    Ui::BookWidget *ui;
};


#endif //EXERCICE07_LIBRARY_BOOKWIDGET_H
