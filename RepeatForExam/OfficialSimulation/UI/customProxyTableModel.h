//
// Created by Sorin Sebastian Mircea on 01/06/2017.
//

#ifndef SIMULATION_PROXYMODEL_H
#define SIMULATION_PROXYMODEL_H


#include <QSortFilterProxyModel>
#include <QDate>
#include <iostream>
#include "../Controller/GradingController.h"
#include <string>

using namespace std;

class CustomProxyTableModel : public QSortFilterProxyModel
{
Q_OBJECT

public:
    CustomProxyTableModel(GradingController *controller, Teacher *teacher, QObject *parent = 0);

    string getFilterTeacherName();
    void setFilterTeacherName(string teacherName);

protected:
    //For filtering
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

    //For sorting
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

public:
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

public:
    GradingController *controller;
    Teacher *teacher;
};


#endif //SIMULATION_PROXYMODEL_H
