#include "RedButton.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RedButton redButton(nullptr);
    redButton.setFixedSize(100, 100);
    redButton.move(1000, 400);
    QObject::connect(&redButton, &QPushButton::clicked, [](){std::cout <<"clicked\n";});
    redButton.show();
    return a.exec();
}
