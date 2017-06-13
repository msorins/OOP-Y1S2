//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#include "customProxyTableModel.h"


CustomProxyTableModel::CustomProxyTableModel(GradingController *controller, Teacher teacher, QObject *parent)
        : controller{controller}, teacher{teacher}, QSortFilterProxyModel(parent)
{

}

bool CustomProxyTableModel::filterAcceptsRow(int sourceRow,
                                        const QModelIndex &sourceParent) const {
    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);

    if(this->teacher.getName().size() == 0)
        return true;

    return true;
    //return this->controller->getStudentsRepo()->getStudentByPosition(sourceRow).getNameOfTeacher() == this->teacher.getName();
}

bool CustomProxyTableModel::lessThan(const QModelIndex &left,
                                const QModelIndex &right) const
{
    int leftColumn = left.column();
    int leftRow = left.row();
    int rightColumn = right.column();
    int rightRow = right.row();

    cout<<"rows: "<<leftRow<<" "<<leftColumn<<" - " <<rightRow<<" "<<rightColumn<<"\n";

    if(this->sortRole() == Qt::InitialSortOrderRole)
        return 0;

    return 0;

}

string CustomProxyTableModel::getFilterTeacherName() {
    return this->teacherName;
}

void CustomProxyTableModel::setFilterTeacherName(string teacherName) {
    this->teacherName = teacherName;
}

