#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QModelIndex>

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ProxyModel(QObject* parent = nullptr);
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;
};

#endif //PROXYMODEL_H

