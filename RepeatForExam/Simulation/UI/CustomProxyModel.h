//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#ifndef SIMULATION_PROXYMODEL_H
#define SIMULATION_PROXYMODEL_H


#include <QSortFilterProxyModel>
#include <QDate>
#include <iostream>
#include "../Repository/Repository.h"

using namespace std;

class CustomProxyModel : public QSortFilterProxyModel
{
Q_OBJECT

public:
    CustomProxyModel(Repository &repo, QObject *parent = 0);

    int filterMaximumPrecipitation() const { return maxPrecipitation; }
    void setFilterMaximumPrecipitation(int precipitation);

protected:
    //For filtering
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

    //For sorting
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

public:


public:
    Repository &repo;
private:


    int maxPrecipitation;
};


#endif //SIMULATION_PROXYMODEL_H
