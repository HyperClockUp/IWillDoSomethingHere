#ifndef UTILS_H
#include "jsoncpp/json/json.h"
#include <QString>
#include <QtDebug>
#define UTILS_H


class Utils
{
public:
    Utils();
    static Json::Value parse(QString json);
    static QString parse(Json::Value root);
};

#endif // UTILS_H
