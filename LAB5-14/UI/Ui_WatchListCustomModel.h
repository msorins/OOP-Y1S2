//
// Created by Sorin Sebastian Mircea on 26/05/2017.
//

#include <QAbstractTableModel>
#include "../Repository/IWatchListRepository.h"

class Ui_WatchListCustomModel : public QAbstractTableModel
{
private:
    IWatchListRepository &repo;

public:
    explicit Ui_WatchListCustomModel(IWatchListRepository &repo, QObject *parent = 0);


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

    // used to set certain properties of a cell
    Qt::ItemFlags flags(const QModelIndex & index) const override;

private:
};

