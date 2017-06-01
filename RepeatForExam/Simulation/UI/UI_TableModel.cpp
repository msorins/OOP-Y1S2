//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#include <QFont>
#include "UI_TableModel.h"

UI_TableModel::UI_TableModel(Repository &repo, QObject *parent) : repo{repo}, QAbstractTableModel(parent)
{
}


QVariant UI_TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole) {
        if(orientation == Qt::Horizontal) {
            switch(section) {
                case 0:
                    return QString::fromStdString("Start Hour");
                    break;
                case 1:
                    return QString::fromStdString("End Hour");
                    break;
                case 2:
                    return QString::fromStdString("Temperature");
                    break;
                case 3:
                    return QString::fromStdString("Precipitation probability");
                    break;
                case 4:
                    return QString::fromStdString("Weather description");
                    break;
            }
        }
    }

    if (role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }


    return QVariant{};
}

/*
bool UI_TableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{x
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}
 */


int UI_TableModel::rowCount(const QModelIndex &parent) const
{
    return this->repo.getSize();
}

int UI_TableModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant UI_TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();

    if(role == Qt::EditRole || role == Qt::DisplayRole) {
        switch(column) {
            case 0:
                return QString::fromStdString(to_string( this->repo.getElemetFromPosition(row).getHourStart()) );
                break;
            case 1:
                return QString::fromStdString(to_string( this->repo.getElemetFromPosition(row).getHourEnd() ));
                break;
            case 2:
                return QString::fromStdString(to_string( this->repo.getElemetFromPosition(row).getTemperature() ));
                break;
            case 3:
                return QString::fromStdString(to_string( this->repo.getElemetFromPosition(row).getPrecipitationProbability() ));
                break;
            case 4:
                return QString::fromStdString( this->repo.getElemetFromPosition(row).getDescription() );
                break;
        }
    }


    return QVariant();
}

bool UI_TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        int row = index.row();
        int column = index.column();
        Weather crtWeatherFromRepo = this->repo.getElemetFromPosition(row);

        switch(column) {
            case 0:
                crtWeatherFromRepo.setHourStart(value.toInt());
                break;
            case 1:
                crtWeatherFromRepo.setHourEnd(value.toInt());
                break;
            case 2:
                crtWeatherFromRepo.setTemperature(value.toInt());
                break;
            case 3:
                crtWeatherFromRepo.setPrecipitationProbability(value.toInt());
                break;
            case 4:
                crtWeatherFromRepo.setDescription(value.toString().toStdString());
                break;
        }

        this->repo.setElementToPosition(crtWeatherFromRepo, row);
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags UI_TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
