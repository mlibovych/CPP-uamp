#include "mainwindow.h"

MainWindow::MainWindow(Mediator *mediator, QWidget *parent) :
                        QMainWindow(parent), Component(mediator)
{
    resize(1200, 700);
    initToolbar();
}

MainWindow::~MainWindow()
{
//
}

void MainWindow::initToolbar() {
    toolBar = new QToolBar(this);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea);
    toolBar->setFloatable(false);
    toolBar->setOrientation(Qt::Vertical);
    toolBar->setMovable(false);
    toolBar->addAction("foo");
    toolBar->addAction("bar");
    addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->hide();
}

void MainWindow::setWidget(QWidget *widget, bool tool) {
    setCentralWidget(widget);
    if (tool) {
        toolBar->show();
    }
    else {
        toolBar->hide();
    }
}
