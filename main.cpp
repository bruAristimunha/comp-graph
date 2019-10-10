#include "tictoc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tictoc w;
    w.show();

    return a.exec();
}
