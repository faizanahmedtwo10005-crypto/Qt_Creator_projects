#include "weather_app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WEATHER_APP w;
    w.show();
    return a.exec();
}
