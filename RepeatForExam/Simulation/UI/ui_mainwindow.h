/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListView *weatherListView;
    QLineEdit *precipitationLineEdit;
    QPushButton *filterButton;
    QPushButton *unFilterButton;
    QLineEdit *descriptionLineEdit;
    QPushButton *computeHoursButton;
    QPushButton *sortButton;
    QPushButton *unsortButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(909, 728);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        weatherListView = new QListView(centralWidget);
        weatherListView->setObjectName(QStringLiteral("weatherListView"));
        weatherListView->setGeometry(QRect(20, 20, 851, 551));
        precipitationLineEdit = new QLineEdit(centralWidget);
        precipitationLineEdit->setObjectName(QStringLiteral("precipitationLineEdit"));
        precipitationLineEdit->setGeometry(QRect(20, 590, 113, 21));
        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setGeometry(QRect(20, 630, 113, 32));
        unFilterButton = new QPushButton(centralWidget);
        unFilterButton->setObjectName(QStringLiteral("unFilterButton"));
        unFilterButton->setGeometry(QRect(150, 580, 111, 91));
        descriptionLineEdit = new QLineEdit(centralWidget);
        descriptionLineEdit->setObjectName(QStringLiteral("descriptionLineEdit"));
        descriptionLineEdit->setGeometry(QRect(300, 590, 351, 21));
        computeHoursButton = new QPushButton(centralWidget);
        computeHoursButton->setObjectName(QStringLiteral("computeHoursButton"));
        computeHoursButton->setGeometry(QRect(300, 630, 371, 32));
        sortButton = new QPushButton(centralWidget);
        sortButton->setObjectName(QStringLiteral("sortButton"));
        sortButton->setGeometry(QRect(690, 590, 181, 32));
        unsortButton = new QPushButton(centralWidget);
        unsortButton->setObjectName(QStringLiteral("unsortButton"));
        unsortButton->setGeometry(QRect(690, 630, 181, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 909, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        precipitationLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Precipitation filter", Q_NULLPTR));
        filterButton->setText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
        unFilterButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        descriptionLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Compute hours with given description", Q_NULLPTR));
        computeHoursButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        sortButton->setText(QApplication::translate("MainWindow", "Sort", Q_NULLPTR));
        unsortButton->setText(QApplication::translate("MainWindow", "Unsort", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
