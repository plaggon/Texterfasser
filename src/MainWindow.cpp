#include "MainWindow.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Texterfasser");
    resize(600, 400);

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    QLabel *label = new QLabel("Welcome to Texterfasser!", central);
    QPushButton *button = new QPushButton("Quit", central);

    layout->addWidget(label);
    layout->addWidget(button);
    setCentralWidget(central);

    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("E&xit", this, &QWidget::close);

    statusBar()->showMessage("Ready");

    connect(button, &QPushButton::clicked, this, &QWidget::close);
}


