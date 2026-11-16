#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

class FileSearchPopup : public QWidget {
    public:
        explicit FileSearchPopup(QWidget *parent = nullptr);

    private:
        QLabel *m_label;
        QPushButton *m_cancelButton;

};