#include <QFont>
#include "tablemodel.h"

TableModel::TableModel(GradingController *controllerInput, QObject *parent)
    : QAbstractTableModel(parent), controller{controllerInput}
{
}


QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString::fromStdString("Id");
                break;
            case 1:
                return QString::fromStdString("Name");
                break;
            case 2:
                return QString::fromStdString("Group");
                break;
            case 3:
                return QString::fromStdString("Grade");
                break;
            case 4:
                return QString::fromStdString("Techer's Name");
                break;

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
bool TableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}
*/


int TableModel::rowCount(const QModelIndex &parent) const
{
    cout<<"rowCount: "<< this->controller->getStudentsRepo()->getSize()<<"\n";
    return this->controller->getStudentsRepo()->getSize();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();

    if(role == Qt::DisplayRole || role == Qt::EditRole) {

        if(column == 0)
            return QString::fromStdString(to_string(this->controller->getStudentsRepo()->getStudentByPosition(row).getId()) );
        if(column == 1)
            return QString::fromStdString(this->controller->getStudentsRepo()->getStudentByPosition(row).getName() );
        if(column == 2)
            return QString::fromStdString(  to_string(this->controller->getStudentsRepo()->getStudentByPosition(row).getGroup() ) );
        if(column == 3)
            return QString::fromStdString(  to_string(this->controller->getStudentsRepo()->getStudentByPosition(row).getGrade() ) );
        if(column == 4)
            return QString::fromStdString(this->controller->getStudentsRepo()->getStudentByPosition(row).getNameOfTeacher() );
    }

    cout<<"row: "<<row<<"\n";

    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    //if (!index.isValid())
        //return Qt::NoItemFlags;

    return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void TableModel::dataChangedX() {

}


