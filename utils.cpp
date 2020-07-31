#include "utils.h"

Utils::Utils()
{

}

Json::Value Utils::parse(QString json)
{
    bool res;
    JSONCPP_STRING errs;
    Json::Value root;
    // 中文不乱码
    std::string str = json.toStdString();
    const char *temp = str.c_str();
    Json::CharReaderBuilder readerBuilder;
    std::unique_ptr<Json::CharReader> const jsonReader(readerBuilder.newCharReader());
    res = jsonReader->parse(temp,temp+json.length(), &root, &errs);
    return root;
}

QString Utils::parse(Json::Value root)
{
    return QString::fromLocal8Bit(root.toStyledString().c_str());
}
