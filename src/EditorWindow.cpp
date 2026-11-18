#include "EditorWindow.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

EditorWindow::EditorWindow(QWidget *parent, QUrl *file_name_pointer, tesseract::TessBaseAPI *api, QTextEdit *editor) : file_name(){
    setWindowFlag(Qt::Window);
    setWindowTitle("Texterfasser Editor");
    resize(600, 400);

    file_name = *file_name_pointer;

    QHBoxLayout *h_layout = new QHBoxLayout(this);
    QVBoxLayout *v_layout = new QVBoxLayout(this);
    QLabel *image_name = new QLabel(this);
    image_name->setText("Current File: " + file_name.path());
    QPushButton *export_button = new QPushButton(this);
    editor = new QTextEdit(this);

    v_layout->addWidget(((QWidget*) editor));
    v_layout->addWidget(export_button);


    h_layout->addWidget(image_name);
    h_layout->addLayout(v_layout);

    api = new tesseract::TessBaseAPI();

    if(api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
    }


}

void EditorWindow::scanLoadedImage() {
    Pix *image = pixRead(file_name.path().toStdString().c_str());
    api->SetImage(image);

    char *outText;

    outText = api->GetUTF8Text();
    editor->setText(outText);
}