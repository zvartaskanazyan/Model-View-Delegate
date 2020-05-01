#include "Info.h"

appInfo::appInfo()    
               : m_appName(QString())
               , m_price(double())
               , m_releaseDate(int())
{
}
appInfo::appInfo(QString name,double price,int date)
               :m_appName(name)
               ,m_price(price)
               ,m_releaseDate(date)
{
}
          
QString appInfo::getName()  const { return m_appName;}

double  appInfo::getPrice() const { return m_price;}

int     appInfo::getDate()  const { return m_releaseDate;}
   
void    appInfo::setName(QString name) { m_appName = name; }

void    appInfo::setPrice(double price){m_price = price; }

void    appInfo::setDate(int data)     {m_releaseDate = data ;}
          
QDebug operator<<(QDebug dbg, const appInfo &info) {
    dbg << info.m_appName;
    dbg << info.m_price;
    dbg << info.m_releaseDate;
    return dbg;
}

