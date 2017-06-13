#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(GradingController *controllerInput, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), controller{controllerInput}
{
    ui->setupUi(this);

    this->setTableView();
    this->createViewsForSecondaryTeachers();
    this->linkSlotWithSignalsOnce();
    this->linkSlotsWithSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: setTableView(){
    //Create the table Model
    this->tableModel = new TableModel{this->controller};

    //Then create the proxy
    Teacher t;
    this->proxyTableModel =  new CustomProxyTableModel(this->controller, &t);
    this->proxyTableModel->setSortRole(Qt::AscendingOrder);
    this->proxyTableModel->setSourceModel(this->tableModel);


    //this->ui->tableView = new QTableView();
    this->ui->tableView->setModel(this->proxyTableModel);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->ui->tableView->setSelectionBehavior( QAbstractItemView:: SelectRows);
}


void MainWindow::linkSlotWithSignalsOnce() {
    QObject::connect(this->ui->addPushButton, SIGNAL(clicked()), this, SLOT(addStudent()));
    QObject::connect(this->ui->deletePushButton, SIGNAL(clicked()), this, SLOT(deleteStudent()));
}

void MainWindow::linkSlotsWithSignals() {

    QObject::connect(this->ui->tableView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(updateDataEverywhere()));
    QObject::connect(this, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(updateDataEverywhere(const QModelIndex&, const QModelIndex&)));

    for(int i = 0; i < this->controller->getTeachersRepo()->getSize(); i++) {
        QObject::connect(this->secondaryTablesModels[i]->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(updateDataEverywhere(const QModelIndex&, const QModelIndex&)));
    }
}

void MainWindow::deleteStudent() {
    cout<<"delete pushed";
    int pos = this->ui->tableView->currentIndex().row();

    int confirmation = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
    if(confirmation == QMessageBox::Yes) {
        this->controller->getStudentsRepo()->removeByPosition(pos);
        this->ui->tableView->update();
    }

    this->updateViewsForSecondaryTeachers();
    this->updateDataEverywhereNoParam();
}

void MainWindow::addStudent() {
    cout << "Added pushed";

    string name = this->ui->nameLineEdit->text().toStdString() ;
    int group = atoi( this->ui->groupLineEdit->text().toStdString().c_str() );

    string empty;
    this->controller->getStudentsRepo()->add(Student(this->controller->getStudentsRepo()->getNewId(), name, group, 1.0, empty ));
    this->ui->tableView->update();
    this->setTableView();
    this->updateViewsForSecondaryTeachers();
    this->updateDataEverywhereNoParam();

}

void MainWindow::createViewsForSecondaryTeachers() {
    this->secondaryProxyTablesModels.erase(this->secondaryProxyTablesModels.begin(), this->secondaryProxyTablesModels.end());
    int i;


    for(i = 0; i < this->controller->getTeachersRepo()->getSize(); i++) {
        this->teachers.push_back( this->controller->getTeachersRepo()->getTeacherList()[i] );

        this->secondaryProxyTablesModels.push_back( new CustomProxyTableModel(this->controller, &teachers[i]) );
        this->secondaryProxyTablesModels[i]->setSortRole(Qt::AscendingOrder);
        this->secondaryProxyTablesModels[i]->setSourceModel(this->tableModel);

        this->secondaryTablesModels.push_back( new QTableView() );
        this->secondaryTablesModels[i]->setWindowTitle(QString::fromStdString(this->teachers[i].getName()));
        this->secondaryTablesModels[i]->setModel(this->secondaryProxyTablesModels[i]);
        this->secondaryTablesModels[i]->setFixedWidth(450);
        this->secondaryTablesModels[i]->resizeColumnsToContents();
        this->secondaryTablesModels[i]->setSortingEnabled(true);
        this->secondaryTablesModels[i]->show();
    }

}

void MainWindow::updateViewsForSecondaryTeachers() {
    for(int i = 0; i < this->controller->getTeachersRepo()->getSize(); i++) {
        this->secondaryProxyTablesModels[i] = new CustomProxyTableModel(this->controller, &this->teachers[i]);
        this->secondaryProxyTablesModels[i]->setSourceModel(this->tableModel);
        this->secondaryTablesModels[i]->setModel(this->secondaryProxyTablesModels[i]);
    }
}

void MainWindow::updateDataEverywhere(const QModelIndex& A, const QModelIndex& B) {
    if(A.row() == -1 && B.row() == -1 && A.column() == -1 && B.column() == -1) {
        QMessageBox::warning(
                this,
                tr("Warning :)"),
                tr("Grade already given by other teacher, sorry") );


    }
    this->updateDataEverywhereNoParam();
}

void MainWindow::updateDataEverywhereNoParam() {
    this->setTableView();
    this->updateViewsForSecondaryTeachers();
    this->linkSlotsWithSignals();
    cout<<"update dataaaaa";
}

