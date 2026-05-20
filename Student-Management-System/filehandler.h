#ifndef FILEHANDLER_H  // Start of header guard: prevents multiple inclusion of this file
#define FILEHANDLER_H   // Marks this file as already included
#include<student.h>
#include<QString>
#include<QList>
class filehandler
{
private:
    QString filename;
public:
    filehandler(QString filename);
    QList<student> loadfromfile();
    void savetofile(QList<student> students);
    ~filehandler();
};

#endif // FILEHANDLER_H
