//
// Created by Administrateur on 17/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BookWidget.h" resolved

#include "bookwidget.h"
#include "ui_BookWidget.h"


BookWidget::BookWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::BookWidget) {
    ui->setupUi(this);
}

BookWidget::~BookWidget() {
    delete ui;
}
