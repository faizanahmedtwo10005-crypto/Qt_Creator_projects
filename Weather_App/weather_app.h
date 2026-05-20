#ifndef WEATHER_APP_H
#define WEATHER_APP_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class WEATHER_APP;
}
QT_END_NAMESPACE

class WEATHER_APP : public QMainWindow
{
    Q_OBJECT

public:
    explicit WEATHER_APP(QWidget *parent = nullptr);
    ~WEATHER_APP() override;

private slots:
    void on_searchButton_clicked();

private:
    Ui::WEATHER_APP *ui;
    QNetworkAccessManager *manager;
        void handleResponse(QByteArray data);
};
#endif // WEATHER_APP_H
