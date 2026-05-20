#ifndef SMS_STUDENT_MANAGEMENT_SYSTEM_H
#define SMS_STUDENT_MANAGEMENT_SYSTEM_H

#include <QMainWindow>
#include<student.h>
#include<filehandler.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class SMS_STUDENT_MANAGEMENT_SYSTEM;
}
QT_END_NAMESPACE

class SMS_STUDENT_MANAGEMENT_SYSTEM : public QMainWindow
{
    Q_OBJECT

public:
    explicit SMS_STUDENT_MANAGEMENT_SYSTEM(QWidget *parent = nullptr);
    ~SMS_STUDENT_MANAGEMENT_SYSTEM() override;
private slots:
    void on_btnadd_clicked();

    void on_btnupdate_clicked();

    void on_btndelete_clicked();

    void on_btnFind_clicked();

private:
    Ui::SMS_STUDENT_MANAGEMENT_SYSTEM *ui;
    filehandler *fileHandler;

    QList<student> students;

    void loadTable();
    void clearInputs();
};
#endif // SMS_STUDENT_MANAGEMENT_SYSTEM_H
