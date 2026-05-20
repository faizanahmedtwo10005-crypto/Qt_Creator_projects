#include "weather_app.h"
#include "ui_weather_app.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QString>
WEATHER_APP::WEATHER_APP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WEATHER_APP)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
}

WEATHER_APP::~WEATHER_APP()
{
    delete ui;
}

void WEATHER_APP::on_searchButton_clicked()
{
    QString city = ui->searchinput->text();  // get city name from input

    QString url = "https://api.openweathermap.org/data/2.5/weather?q="
                  + city +
                  "&appid=7113281c102710e8da07be27f676c19a&units=metric";

    QNetworkRequest request((QUrl(url)));
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        QByteArray data = reply->readAll();
        handleResponse(data);  // we will create this in STEP 7


        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << reply->errorString();
        }
        reply->deleteLater();
    });
}
void WEATHER_APP::handleResponse(QByteArray data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull()) {
        ui->cityname->setText("Error fetching data");
        return;
    }

    QJsonObject obj = doc.object();

    // 🌍 City
    QString city = obj["name"].toString();
    ui->cityname->setText(city);

    // 🌡 Temperature
    double temp = obj["main"].toObject()["temp"].toDouble();
    ui->temperature->setText(QString::number(temp) + "°C");

    // ☁ Weather condition
    QJsonArray weatherArray = obj["weather"].toArray();
    QString condition = weatherArray[0].toObject()["description"].toString();
    if(!condition.isEmpty()) condition[0] = condition[0].toUpper();  // capitalize first letter
    ui->condition->setText(condition);

    // 💧 Humidity
    int humidity = obj["main"].toObject()["humidity"].toInt();
    ui->humidityvalue->setText(QString::number(humidity) + "%");

    // 🌬 Wind Speed
    double wind = obj["wind"].toObject()["speed"].toDouble();
    ui->windvalue->setText(QString::number(wind) + " km/h");

    // 🌡 Feels Like
    double feels = obj["main"].toObject()["feels_like"].toDouble();
    ui->temperaturevalue->setText(QString::number(feels) + "°C");
}

