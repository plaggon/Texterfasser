#include "MainWindow.h"
#include "FileSearchPopup.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Texterfasser");
    resize(600, 400);

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    setCentralWidget(central);

    QMenu *fileMenu = menuBar()->addMenu("&File");
    QAction *fopenButton = new QAction("Open file", this);
    fileMenu->addAction("Exit", this, &QWidget::close);
    fileMenu->addAction(fopenButton);

    connect(fopenButton, &QAction::triggered, this, &MainWindow::openFileExplorer);

}

MainWindow::~MainWindow() {
    
}

void MainWindow::openFileExplorer() {
    FileSearchPopup *popUp = new FileSearchPopup(this);
    popUp->setAttribute(Qt::WA_DeleteOnClose);
    popUp->show();
}



