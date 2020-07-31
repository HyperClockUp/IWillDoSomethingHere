#include "request.h"


Request::Request()
{
    this->initRequest();
}

Json::Value Request::request(QString method,QString url,Json::Value data)
{
    if(method == "post" ||method == "POST"){
        return this->post(url,data);
    }else{
        return this->get(url);
    }
}

Json::Value Request::post(QString url,Json::Value data)
{
    QString dataStr = Utils::parse(data);
    this->httpRequest.setUrl(url);
    this->reply = this->m_pHttpMgr.post(this->httpRequest,dataStr.toUtf8());
    QEventLoop eventLoop;
    QObject::connect(this->reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    //请求返回的结果
    QByteArray responseByte = this->reply->readAll();
    QString result;
    result.prepend(responseByte);
    return Utils::parse(result);
}

Json::Value Request::get(QString url)
{
    this->httpRequest.setUrl(url);
    this->reply = this->m_pHttpMgr.get(this->httpRequest);
    QEventLoop eventLoop;
    QObject::connect(this->reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    //请求返回的结果
    QByteArray responseByte = this->reply->readAll();
    QString result;
    result.prepend(responseByte);
    qDebug()<<result;
    return Utils::parse(result);
}

void Request::initRequest()
{
    this->reply = NULL;
    httpRequest.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
}
