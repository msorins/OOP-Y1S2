//
// Created by Sorin Sebastian Mircea on 26/05/2017.
//

#include "Ui_WatchListCustomModel.h"




Ui_WatchListCustomModel::Ui_WatchListCustomModel(IWatchListRepository &repo, QObject *parent) : repo{repo}, QAbstractTableModel(parent)
{
}

int Ui_WatchListCustomModel::rowCount(const QModelIndex &parent) const
{
    int x = this->repo.getWatchList().size();
    return x;
}


int Ui_WatchListCustomModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant Ui_WatchListCustomModel::data(const QModelIndex &index, int role) const
{

    int row = index.row();
    int column = index.column();

    if(role == Qt::DisplayRole || role == Qt::EditRole) {
        cout<<"column: "<<column<<"\n";

            if(column == 0) {
                string title = this->repo.getWatchList().get(row+1).getTitle();
                return QString::fromStdString(this->repo.getWatchList().get(row+1).getTitle());
            }

            if(column == -1) {
                return QString::fromStdString(to_string(row + 1));
            }

            return QVariant{};
    }


    return QVariant{};
}

bool Ui_WatchListCustomModel::setData(const QModelIndex &index, const QVariant &value, int role) {

    int row = index.row();
    int column = index.column();
    cout<<"Editable: "<<row<<" "<<column<<"\n";
    const QString r = value.toString();
    cout<<"Value: "<<r.toStdString()<<"\n";
}

Qt::ItemFlags Ui_WatchListCustomModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

