#include "comboDelegate.h"
#include <QComboBox>
#include <QAbstractItemModel>

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
    : QItemDelegate(parent)
{
    model = new custom_model;
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent,const QStyleOptionViewItem &option ,const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QComboBox *editor = new QComboBox(parent);
    editor->setModel(model);
    editor->setView(new QTableView);
    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor,const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QVariant value = index.model()->data(index, Qt::EditRole);
    //comboBox->setCurrentIndex(comboBox->findText(value));
    comboBox->setItemData(comboBox->findText(value.toString()),value);
    comboBox->showPopup();
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index,comboBox->currentData(),Qt::EditRole);
    emit model->dataChanged(index,index);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}

