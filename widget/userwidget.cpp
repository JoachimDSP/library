//
// Created by Administrateur on 17/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserWidget.h" resolved

#include "userwidget.h"
#include "ui_UserWidget.h"


UserWidget::UserWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::UserWidget) {
    ui->setupUi(this);
}

UserWidget::~UserWidget() {
    delete ui;
}
