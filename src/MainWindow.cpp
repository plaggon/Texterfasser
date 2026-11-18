#include "MainWindow.h"
#include "EditorWindow.h"
#include "QtWidgets/QFileDialog"
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <string>
#include <vector>
#include <QDir>
#include <QUrl>
#include <QList>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Texterfasser");
    resize(600, 400);

    QWidget *central = new QWidget(this);

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

    QFileDialog dialog(this);
    QList<QUrl> selected_files;

    dialog.setNameFilter(tr("Images (*.png *.jpg)"));
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setDirectory(QDir::homePath());
    dialog.exec();

    selected_files = dialog.selectedUrls();

    EditorWindow *file_editor = new EditorWindow(this, &selected_files[0]);
    file_editor->show();

}



