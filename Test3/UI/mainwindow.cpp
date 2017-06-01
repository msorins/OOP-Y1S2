#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listmodel.h"

MainWindow::MainWindow(Repository &repos, QWidget *parent) : repo{repos}, QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->linkListView();
    this->linkSignalAndSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::linkListView() {
    this->listModel = new ListModel(this->repo);
    this->ui->listView->setModel(listModel);
}

void MainWindow::linkSignalAndSlots() {
    QObject::connect(this->ui->sortButton, SIGNAL(clicked()), this, SLOT(sortBySum()));
    QObject::connect(this->ui->calculateTotalButton, SIGNAL(clicked()), this, SLOT(calculateUnpaidBillsForCompany()));
}

void MainWindow::sortBySum() {
    this->repo.sortByDueDate();
}

void MainWindow::calculateUnpaidBillsForCompany() {
    QString nameQ = this->ui->nameLineEdit->text();
    string name = nameQ.toStdString();

    int res = this->repo.totalUnpaidBillsForCompany(name);

    this->ui->resultLabel->setText(QString::fromStdString( "Result: " + to_string(res) ));

    cout<<name;
}
