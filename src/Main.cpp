#include "MainWindow.h"
#include "QtWidgets/QApplication"
#include <stdio.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();
    printf("Hello World");

    return app.exec();
}