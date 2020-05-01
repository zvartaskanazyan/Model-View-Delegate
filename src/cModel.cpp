#include "cModel.h"
#include <QString>
#include <QTableView>
#include <QBrush>

custom_model::custom_model(QObject *parent ) : QAbstractTableModel(parent)
{
    init();
}
int custom_model::rowCount(const QModelIndex& parent) const {

        Q_UNUSED(parent);   
        return m_appInfo.size(); 
}
int custom_model::columnCount(const QModelIndex& parent) const {

        Q_UNUSED(parent);
        return 3;
}
QVariant custom_model::data(const QModelIndex &index, int role ) const
{
    if (!index.isValid()) {
         return QVariant();
    }
    if( role == Qt::DisplayRole) {
      const appInfo& info = m_appInfo.at(index.row());
      switch (index.column()) {
          case 0:
             return info.getName();
          case 1:
             return info.getPrice();
          case 2:
             return info.getDate();
          default:
             return QVariant();
      }
    }  
    return QVariant();
}

bool custom_model::setData(const QModelIndex &index, const QVariant &value, int role ) 
{
   if (index.isValid() && role == Qt::EditRole) {
     appInfo info = m_appInfo.at(index.row());
      switch(index.column()) {
        case 0: 
        {
            info.setName(value.toString());
            m_appInfo.replace(index.row(),info);
        }
            break;
        case 1: 
        {
            info.setPrice(value.toDouble());
            m_appInfo.replace(index.row(),info);
        }
            break;
        case 2: 
        {   
            info.setDate(value.toInt());
            m_appInfo.replace(index.row(),info);
        }
            break;
        default:
            return false;
      }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}
QVariant custom_model::headerData(int section, Qt::Orientation orientation,int role) const {
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch(section) {
            case 0:
                return QString("App Name"); break;
            case 1:
                return QString("Product Price"); break;
            case 2:
                return QString("Release Date");break;
            default:
                return QVariant(); break;
        }
    } 
    else if(orientation == Qt::Vertical && role == Qt::DisplayRole) {
        return QString(" %1 ").arg(++section);
    }
    return QVariant();
}

Qt::ItemFlags custom_model::flags(const QModelIndex &index) const {
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
} 
void custom_model::init()
{
    m_appInfo.append(appInfo("Krisp",    3.33 ,2018));
    m_appInfo.append(appInfo("Zoom",     19.99,2011));
    m_appInfo.append(appInfo("Skype",    0.00 ,2003));
    m_appInfo.append(appInfo("WebEx",    13.50,1995));
    m_appInfo.append(appInfo("Telegram", 0.00 ,2013));  
}


















