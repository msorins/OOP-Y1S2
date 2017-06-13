//
// Created by Sorin Sebastian Mircea on 12/06/2017.
//

#include <QMessageBox>
#include "customProxyTableModel.h"
#include "../Exception/Exception.h"

CustomProxyTableModel::CustomProxyTableModel(GradingController *controller, Teacher *teacher, QObject *parent)
        : QSortFilterProxyModel(parent)
{
    this->controller = controller;
    this->teacher = teacher;
}

bool CustomProxyTableModel::filterAcceptsRow(int sourceRow,
                                        const QModelIndex &sourceParent) const {

    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);

    if(this->teacher->getName().size() == 0)
        return true;

    for(int i = 0; i < this->teacher->getGroups().size(); i++)
        if( this->teacher->getGroups()[i] == this->controller->getStudentsRepo()->getStudentByPosition(sourceRow).getGroup() )
            return true;

    return false;

}

bool CustomProxyTableModel::lessThan(const QModelIndex &left,
                                const QModelIndex &right) const
{


    int leftColumn = left.column();
    int leftRow = left.row();
    int rightColumn = right.column();
    int rightRow = right.row();

    if(this->sortRole() == Qt::InitialSortOrderRole)
        return 0;

    if(this->sortRole() == Qt::AscendingOrder && leftColumn == 2)
        return this->controller->getStudentsRepo()->getStudentByPosition(leftRow).getGroup() < this->controller->getStudentsRepo()->getStudentByPosition(rightRow).getGroup();

    if(this->sortRole() == Qt::AscendingOrder && leftColumn == 1)
        return this->controller->getStudentsRepo()->getStudentByPosition(leftRow).getName() < this->controller->getStudentsRepo()->getStudentByPosition(rightRow).getName();

    return 0;
}

string CustomProxyTableModel::getFilterTeacherName() {
    return this->teacher->getName();
}

void CustomProxyTableModel::setFilterTeacherName(string teacherName) {
    this->teacher->setName( teacherName );
}

bool CustomProxyTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (data(index, role) != value) {


        auto sourceIndex = mapToSource(index);
        int id  = this->sourceModel()->data(createIndex(sourceIndex.row(), 0)).toInt();

        Student s = this->controller->getStudentsRepo()->getStudentById(id);
        if(s.getNameOfTeacher().size() != 0 && this->teacher->getName() != s.getNameOfTeacher()) {
            emit dataChanged(createIndex(-1,-1), createIndex(-1,-1));
            return false;

        } else {
            s.setGrade(value.toDouble());
            string name = this->teacher->getName();
            s.setNameOfTeacher(name);
            this->controller->getStudentsRepo()->setStudentById(s.getId(), s);

            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}


