#include "sms_student_management_system.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SMS_STUDENT_MANAGEMENT_SYSTEM w;
    w.show();
    return QCoreApplication::exec();
}
