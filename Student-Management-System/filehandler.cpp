#include "filehandler.h"
#include<QList>
#include<QFile>
#include<QDebug>
#include<QTextStream>
#include <QStringList>
filehandler::filehandler(QString filename) {
    this->filename = filename;
}
QList<student> filehandler:: loadfromfile(){
    QList<student> students;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() <<"Could Not Open File For Reading";
        return students;
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        if(line.trimmed().isEmpty()){
            continue;
        }
        QStringList parts = line.split(",");
        if(parts.size() == 4){
            int id = parts[0].toInt();
            QString name= parts[1];
            QString course = parts[2];
            QString dob = parts[3];
            student s(id,name,course,dob);
            students.append(s);
        }
    }
    file.close();
        return students;
}
void filehandler:: savetofile(QList<student> students){
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() <<"Could Not Open File For Writing";
    }
    QTextStream out(&file);
    for(student s: students){
        out<<s.getid()<<","
            <<s.getname()<<","
            <<s.getcourse()<<","
            <<s.getdob()<<"\n";
    }
    file.close();
}
filehandler::~filehandler(){
    qDebug()<<"Filehandler Destroyed";
}