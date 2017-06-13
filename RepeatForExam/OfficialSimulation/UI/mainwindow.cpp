#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(GradingController *controllerInput, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), controller{controllerInput}
{
    ui->setupUi(this);
    this->setTableView();
    this->linkSlotsWithSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: setTableView(){
    this->tableModel = new TableModel{this->controller};

    //this->ui->tableView = new QTableView();
    this->ui->tableView->setModel(this->tableModel);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView->setSelectionBehavior( QAbstractItemView:: SelectRows);
}

void MainWindow::linkSlotsWithSignals() {
    QObject::connect(this->ui->addPushButton, SIGNAL(clicked()), this, SLOT(addStudent()));
    QObject::connect(this->ui->deletePushButton, SIGNAL(clicked()), this, SLOT(deleteStudent()));
}

void MainWindow::deleteStudent() {
    cout<<"delete pushed";
    int pos = this->ui->tableView->currentIndex().row();

    int confirmation = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
    if(confirmation == QMessageBox::Yes) {
        this->controller->getStudentsRepo()->removeByPosition(pos);
        this->ui->tableView->update();
    }
}

void MainWindow::addStudent() {
    cout << "Added pushed";

    string name = this->ui->nameLineEdit->text().toStdString() ;
    int group = atoi( this->ui->groupLineEdit->text().toStdString().c_str() );

    string empty;
    this->controller->getStudentsRepo()->add(Student(this->controller->getStudentsRepo()->getNewId(), name, group, 1.0, empty ));
    this->ui->tableView->update();
    this->setTableView();

}

void MainWindow::createViewsForSecondaryTeachers() {
    this->secondaryTables.erase(this->secondaryTables.begin(), this->secondaryTables.end());

    for(int i = 0; i < this->controller->getTeachersRepo()->getSize(); i++)
        this->secondaryTables[i] = new CustomProxyTableModel(this->controller, this->controller->getTeachersRepo()->getTeacherList()[i]);
        this->secon

}
