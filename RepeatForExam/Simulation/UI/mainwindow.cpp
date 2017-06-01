
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CustomProxyModel.h"

MainWindow::MainWindow(Repository &repo, QWidget *parent) : repo{repo}, QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->populateWeatherListView();
    this->linkStuff();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateWeatherListView() {
    //Create the Model
    this->uiListModel = new UI_List(this->repo);

    this->proxyModel = new CustomProxyModel{this->repo};
    this->proxyModel->setSourceModel(this->uiListModel);

    //Put the model in lis
    this->ui->weatherListView->setModel(proxyModel);
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
    this->proxyModel->setSortRole(Qt::AscendingOrder);
    this->proxyModel->sort(0, Qt::AscendingOrder);

    this->proxyModel->invalidate();
    this->proxyModel->sortColumn();
}

void MainWindow::removeSorting() {
    cout<<"unsort";
    this->proxyModel->setSortRole(Qt::InitialSortOrderRole);

    this->proxyModel->invalidate();
    this->proxyModel->sortColumn();

}

void MainWindow::precipitationFilter() {
    int number = stoi(this->ui->precipitationLineEdit->text().toStdString());
    this->proxyModel->setFilterMaximumPrecipitation(number);
}

void MainWindow::removePrecipitationFilter() {
    this->proxyModel->setFilterMaximumPrecipitation(-1);
}
