#ifndef INFO_H
#define INFO_H

#include <QString>
#include <QDebug>

class appInfo {
    public: 
        appInfo();    
        appInfo(QString name,double price,int date);
                
        QString getName()  const;
        double  getPrice() const;
        int     getDate()  const;
 
        void    setName(QString name);
        void    setPrice(double price);
        void    setDate(int data);
        
        friend QDebug operator<<(QDebug dbg, const appInfo &info); 
    private:
        QString m_appName;
        double  m_price;
        int     m_releaseDate;
};
#endif //INFO_H
