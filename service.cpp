#include "service.h"

Service::Service()
{
    this->BaseUrl = "http://120.79.138.49:520";
}

Json::Value Service::getMusicTags()
{
    Service *s = new Service();
    QString url = s->BaseUrl + "/playlist/hot";
    Request xml;
    Json::Value res = xml.get(url);
    return res;
}

Json::Value Service::getHighQualityList(QString cat,int limit,long before )
{
    Service *s = new Service();
    QString url = s->BaseUrl + "/top/playlist/highquality?before=1503639064131&limit=3";
    Request xml;
    Json::Value res = xml.get(url);
    return res;
}
