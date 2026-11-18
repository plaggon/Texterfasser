#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMainWindow>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QtWidgets/QTextEdit>
#include <QUrl>

class EditorWindow : public QWidget {
    private:
        QUrl file_name;
        QTextEdit *editor;
        tesseract::TessBaseAPI *api;
    public:
        explicit EditorWindow(QWidget *parent, QUrl *file_name, tesseract::TessBaseAPI *api = nullptr, QTextEdit *editor = nullptr);
        void scanLoadedImage();



};