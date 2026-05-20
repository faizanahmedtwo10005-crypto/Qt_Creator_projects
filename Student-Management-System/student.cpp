#include "student.h"
#include<QDebug>
student::student() {
    id = 0;
    course = "";
    name = "";
    dob = "";
}
student :: student(int id, QString name,QString course, QString dob){
    this->id =id;
    this->name = name;
    this->course = course;
    this->dob = dob;
}
QString student:: getcourse(){
    return course;
};
int student::getid(){
    return id;
};
void student:: setcourse(QString course){
    this->course = course;
};
void student:: setid(int id){
    this->id = id;
};
void student :: display(){
    qDebug()<<"ID: "<<id
             <<"NAME: "<<name
             <<"COURSE: "<<course
             <<"DOB: "<<dob;
}
student:: ~student(){

};