#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "../Controller/GradingController.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    GradingController *controller;

public:
    explicit TableModel(GradingController *controllerInput, QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    //bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void dataChangedX();



private:
};

#endif // TABLEMODEL_H
