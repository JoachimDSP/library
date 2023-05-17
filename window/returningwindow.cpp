//
// Created by Administrateur on 17/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ReturningWindow.h" resolved

#include "returningwindow.h"
#include "ui_ReturningWindow.h"


ReturningWindow::ReturningWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::ReturningWindow) {
    ui->setupUi(this);
}

ReturningWindow::~ReturningWindow() {
    delete ui;
}
