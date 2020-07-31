#ifndef REQUEST_H
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QAbstractAnimation>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTextCodec>
#include <QString>
#include <QUrl>
#include <QObject>
#include "jsoncpp/json/json.h"
#include <QDebug>
#include "utils.h"
#define REQUEST_H


class Request :public QObject
{
public:
    Request();
    Json::Value post(QString url,Json::Value data);
    Json::Value get(QString url);
    Json::Value request(QString method,QString url,Json::Value data);
    QNetworkAccessManager m_pHttpMgr;
    QNetworkRequest httpRequest;
    QNetworkReply *reply;
private:
    QSettings *settings;
    void initRequest();

};

#endif // REQUEST_H
