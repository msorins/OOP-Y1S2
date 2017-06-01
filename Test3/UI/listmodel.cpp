#include "listmodel.h"
#include <QColor>
#include <QBrush>

ListModel::ListModel(Repository &repos, QObject *parent) : repo{repos}, QAbstractListModel(parent)
{

}

/*
QVariant ListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

bool ListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}
*/

int ListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.

    vector<Bill> bills = this->repo.getAll();
    return (int)bills.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    vector<Bill> bills = this->repo.getAll();

    if(role == Qt::DisplayRole || role == Qt::EditRole) {
        string output = bills[row].getName() + " ( " + to_string(bills[row].getSum()) + " )";
        return QString::fromStdString(output);
    }

    if (role == Qt::BackgroundRole)
    {
        bool paid = bills[row].isIsPaid();

        if(bills[row].isIsPaid() == false) {
            QBrush *brush = new QBrush();
            brush->setColor(Qt::red);
            brush->setStyle(Qt::SolidPattern);
            return *brush;
        } else {
            QBrush *brush = new QBrush();
            brush->setColor(Qt::green);
            brush->setStyle(Qt::SolidPattern);
            return *brush;
        }

    }

    return QVariant();
}

bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
