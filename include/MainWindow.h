#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow {


public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private:
    void openFileExplorer();

};