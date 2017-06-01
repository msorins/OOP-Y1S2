#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include "../Repository/Repository.h"

class ListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    Repository& repo;

public:
    explicit ListModel(Repository& repos, QObject *parent = 0);

    /*
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
    */

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
};

#endif // LISTMODEL_H
