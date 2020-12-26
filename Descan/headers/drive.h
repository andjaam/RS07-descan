#ifndef DRIVE_H
#define DRIVE_H

#include <QString>
#include <QOAuth2AuthorizationCodeFlow>
#include <QDesktopServices>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QOAuthHttpServerReplyHandler>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
#include <QHttpPart>
#include <QHttpMultiPart>
#include <QVariant>
#include <QByteArray>
#include <QAbstractOAuth>
#include <QObject>

class Drive : public QObject
{
    Q_OBJECT


public:

    Drive();
    ~Drive();

    void uploadToDrive(const QString& filePath);
    void saveTokenAndConnect();
    void postRequest();
    void putRequest();

private:
     QOAuth2AuthorizationCodeFlow* google;
     QNetworkAccessManager* manager;
     QNetworkReply* reply;
     QFile* tokenFile;
     QString filePath;
};

#endif // DRIVE_H