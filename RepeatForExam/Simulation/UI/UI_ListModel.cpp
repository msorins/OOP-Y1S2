#include "UI_ListModel.h"

UI_ListModel::UI_ListModel(Repository &repo,QObject *parent) : repo{repo}, QAbstractListModel(parent)
{
}


QVariant UI_ListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
        return QString{"Gene name"};

    return QVariant{};
}

/*
bool UI_ListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        //// FIXME: Implement me!
        //emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}
*/

int UI_ListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    return this->repo.getSize();
}

QVariant UI_ListModel::data(const QModelIndex &index, int role) const
{

    int row = index.row();

    if(role == Qt::DisplayRole || role == Qt::EditRole) {
        string afisare;
        //if(this->repo.getElemetFromPosition(row).getHourStart() < 10)
            //afisare = "0";

        afisare += to_string(this->repo.getElemetFromPosition(row).getHourStart()) + " - ";
        //if(this->repo.getElemetFromPosition(row).getHourEnd() < 10)
            //afisare += "0";
        afisare += to_string(this->repo.getElemetFromPosition(row).getHourEnd()) + ": " + this->repo.getElemetFromPosition(row).getDescription();
        return QString::fromStdString(afisare);

    }

    return QVariant();
}

bool UI_ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        cout<<"emiteeed";
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags UI_ListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled; // FIXME: Implement me!
}
