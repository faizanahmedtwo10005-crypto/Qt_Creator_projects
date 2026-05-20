#ifndef STUDENT_H
#define STUDENT_H
#include<person.h>
#include<QString>

class student:public person{
private:
    int id;
    QString course;
public:
    student();
    student(int id, QString name, QString course, QString dob);
    QString getcourse();
    int getid();
    void setcourse(QString course);
    void setid(int id);
    void display() override;
    ~student();
};

#endif // STUDENT_H
