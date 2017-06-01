
#include <QTableView>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CustomProxyModel.h"

MainWindow::MainWindow(Repository &repo, QWidget *parent) : repo{repo}, QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->populateWeatherListView();
    this->linkStuff();
    this->createAndPopulateWeatherTableView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateWeatherListView() {
    //Create the Model
    this->uiListModel = new UI_ListModel(this->repo);

    this->customProxyListModel = new CustomProxyModel{this->repo};
    this->customProxyListModel->setSourceModel(this->uiListModel);

    //Put the model in lis
    this->ui->weatherListView->setModel(customProxyListModel);
    this->ui->weatherListView->show();

}

void MainWindow::linkStuff() {
    QObject::connect(this->ui->computeHoursButton, SIGNAL(clicked()), this, SLOT(computeHours()));
    QObject::connect(this->ui->sortButton, SIGNAL(clicked()), this, SLOT(sortAsc()));
    QObject::connect(this->ui->unsortButton, SIGNAL(clicked()), this, SLOT(removeSorting()));
    QObject::connect(this->ui->filterButton, SIGNAL(clicked()), this, SLOT(precipitationFilter()));
    QObject::connect(this->ui->unFilterButton, SIGNAL(clicked()), this, SLOT(removePrecipitationFilter()));
}

void MainWindow::computeHours() {
    string description = this->ui->descriptionLineEdit->text().toStdString();

    int res = this->repo.computeHoursByDescription(description);
    this->ui->descriptionLineEdit->setText(QString::fromStdString("Result: " + to_string(res)));
}

void MainWindow::sortAsc() {
    this->customProxyListModel->setSortRole(Qt::AscendingOrder);
    this->customProxyListModel->sort(0, Qt::AscendingOrder);

    this->customProxyListModel->invalidate();
    this->customProxyListModel->sortColumn();
}

void MainWindow::removeSorting() {
    cout<<"unsort";
    this->customProxyListModel->setSortRole(Qt::InitialSortOrderRole);

    this->customProxyListModel->invalidate();
    this->customProxyListModel->sortColumn();

}

void MainWindow::precipitationFilter() {
    int number = stoi(this->ui->precipitationLineEdit->text().toStdString());
    this->customProxyListModel->setFilterMaximumPrecipitation(number);
}

void MainWindow::removePrecipitationFilter() {
    this->customProxyListModel->setFilterMaximumPrecipitation(-1);
}

void MainWindow::createAndPopulateWeatherTableView() {
    //Create the model
    this->uiTableModel = new UI_TableModel{this->repo};

    //Create the proxy
    this->customProxyMapModel = new CustomProxyModel{this->repo};
    this->customProxyMapModel->setSourceModel(this->uiTableModel);


    QTableView *tableView = new QTableView();
    tableView->setModel(this->customProxyMapModel);
    tableView->setFixedWidth(909);
    tableView->show();
    tableView->resizeColumnsToContents();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setSortingEnabled(true);


    this->customProxyMapModel2 = new CustomProxyModel{this->repo};
    this->customProxyMapModel2->setSourceModel(this->uiTableModel);

    QTableView *tableView2 = new QTableView();
    tableView2->setModel(this->customProxyMapModel2);

    tableView2->setFixedWidth(909);
    tableView2->show();
    tableView2->resizeColumnsToContents();
    tableView2->hideColumn(3);
    tableView2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView2->setSortingEnabled(true);

}
