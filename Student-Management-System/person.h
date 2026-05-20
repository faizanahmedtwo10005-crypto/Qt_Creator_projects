#ifndef PERSON_H
#define PERSON_H
#include<QString>
class person
{
protected:
    QString name;
    QString dob;
public:
    person();
    person(QString name,QString dob);
    QString getname();
    QString getdob();
    void setname(QString name);
    void setdob(QString dob);
    virtual void display();
    virtual ~person();
};

#endif // PERSON_H
