QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filehandler.cpp \
    main.cpp \
    person.cpp \
    sms_student_management_system.cpp \
    student.cpp

HEADERS += \
    filehandler.h \
    person.h \
    sms_student_management_system.h \
    student.h

FORMS += \
    sms_student_management_system.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
