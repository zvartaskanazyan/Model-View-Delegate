#include <QApplication>
#include <QHeaderView>
#include <QTableView>
#include "cModel.h"
#include "proxyModel.h"
#include "comboDelegate.h"
#include <QItemSelectionModel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTableView tableView;
    tableView.setModel(new custom_model); 

    QHeaderView* horHeader = tableView.horizontalHeader();
    horHeader->setDefaultSectionSize(300);
    QHeaderView* verHeader = tableView.verticalHeader();
    verHeader->setDefaultSectionSize(50);
    
    //QItemSelectionModel* select = tableView.selectionModel(); 
    tableView.model()->setParent(&app); 
    QTableView table1;
    custom_model* customModel = new custom_model;
    //table1.setModel(customModel);
    //table1.setSelectionModel(select);

    ProxyModel* proxy = new ProxyModel;
    proxy->setSourceModel(customModel);
    //table1.setModel(proxy);
    //table1.setSortingEnabled(true);
    
    ComboBoxDelegate* comboDelegate = new ComboBoxDelegate(&tableView);
    tableView.setItemDelegate(comboDelegate);
    tableView.show();
    //table1.show();

    return app.exec();
}





