#include "sms_student_management_system.h"
#include "ui_sms_student_management_system.h"
#include <QMessageBox>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
SMS_STUDENT_MANAGEMENT_SYSTEM::SMS_STUDENT_MANAGEMENT_SYSTEM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SMS_STUDENT_MANAGEMENT_SYSTEM)
{
    ui->setupUi(this);
    fileHandler = new filehandler("students.csv");
    students = fileHandler->loadfromfile();
    loadTable();
    ui->studentTable->setColumnWidth(0, 80);
    ui->studentTable->setColumnWidth(1, 180);
    ui->studentTable->setColumnWidth(2, 180);
    ui->studentTable->setColumnWidth(3, 150);
    ui->studentTable->setColumnWidth(4, 150);
}
SMS_STUDENT_MANAGEMENT_SYSTEM::~SMS_STUDENT_MANAGEMENT_SYSTEM()
{
    delete fileHandler;
    delete ui;
}
void SMS_STUDENT_MANAGEMENT_SYSTEM::loadTable() {

    ui->studentTable->setRowCount(0);

    for (int i = 0; i < students.size(); i++) {
        ui->studentTable->insertRow(i);
        ui->studentTable->setItem(i, 0,new QTableWidgetItem(QString::number(students[i].getid())));
        ui->studentTable->setItem(i, 1, new QTableWidgetItem(students[i].getname()));

        ui->studentTable->setItem(i, 2,new QTableWidgetItem(students[i].getcourse()));

        ui->studentTable->setItem(i, 3, new QTableWidgetItem(students[i].getdob()));
        QWidget     *actionWidget = new QWidget();
        QHBoxLayout *layout       = new QHBoxLayout(actionWidget);
        QPushButton *editBtn   = new QPushButton("Edit");
        QPushButton *deleteBtn = new QPushButton("Delete");
        editBtn->setStyleSheet(
            "background-color: #cc0000;"
            "color: white;"
            "padding: 3px;"
            "border-radius: 3px;");
        deleteBtn->setStyleSheet(
            "background-color: #880000;"
            "color: white;"
            "padding: 3px;"
            "border-radius: 3px;");
        layout->addWidget(editBtn);
        layout->addWidget(deleteBtn);
        layout->setContentsMargins(2,2,2,2);
        actionWidget->setLayout(layout);
        ui->studentTable->setCellWidget(i, 4, actionWidget);
        connect(editBtn, &QPushButton::clicked,
                this, [this, i]() {
                    ui->id->setText(QString::number(students[i].getid()));
                    ui->name->setText(students[i].getname());
                    ui->major->setText(students[i].getcourse());
                    ui->birthdate->setText(students[i].getdob());
                });
        connect(deleteBtn, &QPushButton::clicked,
                this, [this, i]() {
                    QMessageBox::StandardButton reply;
                    reply = QMessageBox::question(this,"Delete Student","Are you sure you want to delete?",
                                                  QMessageBox::Yes | QMessageBox::No);
                    if (reply == QMessageBox::Yes) {
                        students.removeAt(i);
                        fileHandler->savetofile(students);
                        loadTable();
                    }
                });
    }
}
void SMS_STUDENT_MANAGEMENT_SYSTEM::on_btnadd_clicked() {
    QString idText = ui->id->text().trimmed();
    QString name   = ui->name->text().trimmed();
    QString course = ui->major->text().trimmed();
    QString dob    = ui->birthdate->text().trimmed();
    if (idText.isEmpty() || name.isEmpty() || course.isEmpty() || dob.isEmpty()) {
        QMessageBox::warning(this,"Empty Fields",
                    "Please fill all fields!");
    }
    student newStudent(idText.toInt(), name, course, dob);
    students.append(newStudent);
    fileHandler->savetofile(students);
    loadTable();
    clearInputs();
    QMessageBox::information(this,"Success", "Student added successfully!");
    return;
}
void SMS_STUDENT_MANAGEMENT_SYSTEM::on_btnupdate_clicked() {
    QString idText = ui->id->text().trimmed();
    QString name   = ui->name->text().trimmed();
    QString course = ui->major->text().trimmed();
    QString dob    = ui->birthdate->text().trimmed();
    if (idText.isEmpty() || name.isEmpty() ||
        course.isEmpty() || dob.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields","Please fill all fields!");
        return;
    }
    int id = idText.toInt();
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getid()==id) {
            students[i].setname(name);
            students[i].setcourse(course);
            students[i].setdob(dob);
            fileHandler->savetofile(students);
            loadTable();
            clearInputs();
            QMessageBox::information(this, "Success", "Record updated successfully!");
            return;
        }
    }
    QMessageBox::warning(this,"Not Found", "Student ID not found!");
}
void SMS_STUDENT_MANAGEMENT_SYSTEM::on_btndelete_clicked() {
    QString idText = ui->id->text().trimmed();
    if (idText.isEmpty()) {
        QMessageBox::warning(this,"Empty Field","Please enter Student ID!");
        return;
    }
    int id = idText.toInt();
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getid() == id) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this,"Delete Student","Are you sure you want to delete?",
                                          QMessageBox::Yes | QMessageBox::No );
            if (reply == QMessageBox::Yes) {
                students.removeAt(i);
                fileHandler->savetofile(students);
                loadTable();
                clearInputs();
                QMessageBox::information(this,"Success", "Student deleted!");
            }
            return;
        }
    }
    QMessageBox::warning(this,
                         "Not Found", "Student ID not found!");
}
void SMS_STUDENT_MANAGEMENT_SYSTEM::on_btnFind_clicked() {
    QString search = ui->searchInput->text().trimmed();
    if (search.isEmpty()) {
        loadTable();
        return;
    }
    ui->studentTable->setRowCount(0);
    int row = 0;
    for (int i = 0; i < students.size(); i++) {
        if (QString::number(students[i].getid()).contains(search, Qt::CaseInsensitive) ||
            students[i].getname().contains( search, Qt::CaseInsensitive) ||
            students[i].getcourse().contains(search, Qt::CaseInsensitive) ||
            students[i].getdob().contains( search, Qt::CaseInsensitive)) {
            ui->studentTable->insertRow(row);
            ui->studentTable->setItem(row, 0,new QTableWidgetItem( QString::number(students[i].getid())));
            ui->studentTable->setItem(row, 1,new QTableWidgetItem(students[i].getname()));
            ui->studentTable->setItem(row, 2,new QTableWidgetItem(students[i].getcourse()));
            ui->studentTable->setItem(row, 3, new QTableWidgetItem(students[i].getdob()));
            row++;
        }
    }
}
void SMS_STUDENT_MANAGEMENT_SYSTEM::clearInputs() {
    ui->id->clear();
    ui->name->clear();
    ui->major->clear();
    ui->birthdate->clear();
}
