#ifndef SERVICE_H
#include <jsoncpp/json/json.h>
#include "request.h"
#define SERVICE_H


class Service
{
public:
    Service();
    QString BaseUrl;
    static Json::Value getMusicTags();
    static Json::Value getHighQualityList(QString cat,int limit,long before = 1503639064131 );

};

#endif // SERVICE_H
