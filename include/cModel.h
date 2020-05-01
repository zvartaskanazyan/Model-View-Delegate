#ifndef CMODEL_H
#define CMODEL_H

#include <QAbstractTableModel>
#include <QObject> 
#include <QModelIndex>
#include <QVariant>
#include <QList>
#include "Info.h"

class custom_model : public QAbstractTableModel {

            Q_OBJECT
    public:
        custom_model(QObject *parent = nullptr);
        Qt::ItemFlags flags(const QModelIndex &index) const;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
        QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override; 
    
    private:
        QList<appInfo> m_appInfo;
        void init();
};

#endif //CMODEL_H
