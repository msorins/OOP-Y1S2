//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#include "CustomProxyModel.h"

CustomProxyModel::CustomProxyModel(Repository &repo, QObject *parent)
        : repo{repo}, QSortFilterProxyModel(parent)
{
    this->maxPrecipitation = -1;
}


void CustomProxyModel::setFilterMaximumPrecipitation(int precipitation)
{
    maxPrecipitation = precipitation;
    invalidateFilter();
}

bool CustomProxyModel::filterAcceptsRow(int sourceRow,
                                              const QModelIndex &sourceParent) const {
    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);

    if(this->maxPrecipitation == -1)
        return true;

    if(this->repo.getElemetFromPosition(sourceRow).getPrecipitationProbability() < this->maxPrecipitation)
        return true;
    return false;
}

bool CustomProxyModel::lessThan(const QModelIndex &left,
                                      const QModelIndex &right) const
{
    int leftRow = left.row();
    int rightRow = right.row();

    cout<<"rows: "<<leftRow<<" "<<rightRow<<"\n";

    if(this->sortRole() == Qt::InitialSortOrderRole)
        return 0;

    if( this->repo.getElemetFromPosition(leftRow).getHourStart() == this->repo.getElemetFromPosition(rightRow).getHourStart())
        return this->repo.getElemetFromPosition(leftRow).getHourEnd() < this->repo.getElemetFromPosition(rightRow).getHourEnd();

    return this->repo.getElemetFromPosition(leftRow).getHourStart() < this->repo.getElemetFromPosition(rightRow).getHourStart();

}

