#include "person.h"
#include<QDebug>
person::person() {
    name = "";
    dob = "";
}
person ::person(QString name,QString dob){
    this->name = name;
    this->dob= dob;
}
QString person:: getname(){
    return name;
}
QString person:: getdob(){
    return dob;
}
void person::setname(QString name){
    this->name=name;
};
void person::setdob(QString dob){
    this->dob = dob;
};
void person :: display(){
    qDebug() <<"NAME: "<<name<<"DOB: "<<dob;
}
person:: ~person(){

}