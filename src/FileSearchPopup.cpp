#include "FileSearchPopup.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

FileSearchPopup::FileSearchPopup(QWidget *parent) : QWidget(parent) {
    setWindowTitle("File Explorer");
    resize(400, 250);

    setWindowFlags(Qt::Window);

    m_label = new QLabel("Select an image file", this);
    m_cancelButton = new QPushButton("Cancel");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->addWidget(m_cancelButton);

    connect(m_cancelButton, &QPushButton::clicked, this, &QWidget::close);

}