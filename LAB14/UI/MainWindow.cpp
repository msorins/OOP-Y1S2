//
// Created by Sorin Sebastian Mircea on 17/05/2017.
//

#include "MainWindow.h"
#include "Ui_MainWindow.h"
#include "../Others/Iterator.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#define CHROME "open '/Applications/Google Chrome.app/Contents/Versions/58.0.3029.110/Google Chrome Helper.app'"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->movieController = new  MovieController< FSTL >( new CSVWatchListRepository() );
    this->movieController->getWatchListRepository()->saveCustom();

    ui->setupUi(this);
    this->populateMovieList();
    this->populateWatchList();
    this->populateMovieToUser();
    this->connectSignalsWithSlots();
    this->setAddWatchListFalse();

    this->createPieChart();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createPieChart() {
    //Delete CHARTVIEW FIRST
    this->ui->pieVerticalLayout->removeWidget(this->chartView);


    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();

    Iterator< Movie> st1( this->movieController->getMovieRepository().begin() );
    Iterator< Movie> dr1( this->movieController->getMovieRepository().end() );

    //Then add items to that list
    for (Iterator< Movie > it=st1; it!=dr1; it++) {
        Movie movie = *it;
        series->append(QString::fromStdString( movie.getTitle() + "(" + to_string(movie.getLikes()) +")" ), movie.getLikes());
    }

    QtCharts::QPieSlice *slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Piechart with Movie Likes");
    chart->legend()->show();


    this->chartView = new QtCharts::QChartView(chart);
    this->chartView->setRenderHint(QPainter::Antialiasing);

    this->ui->pieVerticalLayout->addWidget(this->chartView);

}

void MainWindow::populateMovieList() {

    if( this->ui->moviesListWidget > 0)
        this->ui->moviesListWidget->clear();

    Iterator< Movie> st1( this->movieController->getMovieRepository().begin() );
    Iterator< Movie> dr1( this->movieController->getMovieRepository().end() );

    //Then add items to that list
    for (Iterator< Movie > it=st1; it!=dr1; it++) {
        Movie crt = *it;

        string string = crt.getTitle();
        string +=  "  |  " + crt.getGenre() + "  |  " + to_string(crt.getLikes()) + "  |  " + to_string(crt.getYear());
        QString itemText = QString::fromStdString(string);
        QListWidgetItem *item = new QListWidgetItem{itemText};

        this->ui->moviesListWidget->addItem(item);
    }
}

void MainWindow::populateWatchList() {

    if( this->ui->watchListWidget > 0)
        this->ui->watchListWidget->clear();

    Iterator< WatchListItem > st1( this->movieController->getWatchListRepository()->begin() );
    Iterator< WatchListItem > dr1( this->movieController->getWatchListRepository()->end() );

    //Then add items to that list
    for (Iterator< WatchListItem > it=++st1; it!=dr1; it++) {
        WatchListItem crt = *it;

        string string = crt.getTitle();
        QString itemText = QString::fromStdString(string);
        QListWidgetItem *item = new QListWidgetItem{itemText};

        this->ui->watchListWidget->addItem(item);
    }
}

void MainWindow::connectSignalsWithSlots() {
    //ADMIN AREA
    QObject::connect(this->ui->addButton, SIGNAL(clicked()), this, SLOT(addMovie()));
    QObject::connect(this->ui->editButton, SIGNAL(clicked()), this, SLOT(editMovie()));
    QObject::connect(this->ui->eraseButton, SIGNAL(clicked()), this, SLOT(eraseMovie()));
    QObject::connect(this, SIGNAL(moviesUpdated()), this, SLOT(populateMovieList()));
    QObject::connect(this, SIGNAL(moviesUpdated()), this, SLOT(createPieChart()));

    QObject::connect(this->ui->undoButton, SIGNAL(clicked()), this, SLOT(executeUndo()));
    QObject::connect(this->ui->redoButton, SIGNAL(clicked()), this, SLOT(executeRedo()));

    //USER AREA
    QObject::connect(this->ui->eraseWatchListButton, SIGNAL(clicked()), this, SLOT(eraseWatchList()));
    QObject::connect(this->ui->likeButton, SIGNAL(clicked()), this, SLOT(likeMovie()));
    QObject::connect(this, SIGNAL(watchListUpdated()), this, SLOT(populateWatchList()));

    QObject::connect(this->ui->nextButton, SIGNAL(clicked()), this, SLOT(nextMovie()));
    QObject::connect(this, SIGNAL(currentMovieChanged()), this, SLOT(populateMovieToUser()));

    QObject::connect(this->ui->seeTrailerButton, SIGNAL( clicked() ), this, SLOT(seeTrailerMovie()));
    QObject::connect(this->ui->addWatchListButton, SIGNAL( clicked() ), this, SLOT(addWatchList()));
}

void MainWindow::addMovie() {

    string title = this->ui->titleLineEdit->text().toStdString();
    string genre = this->ui->genreLineEdit->text().toStdString();
    int year = stoi(this->ui->yearLineEdit->text().toStdString());
    int likes = stoi(this->ui->likesLineEdit->text().toStdString());
    string trailer = this->ui->trailerLineEDit->text().toStdString();

    //Compute the add operation
    this->movieController->add(title, genre, year, likes, trailer);

    //Emit an signal that announces a change in movies list
    emit moviesUpdated();

}

void MainWindow::editMovie() {
    QModelIndex index = this->ui->moviesListWidget->currentIndex();
    int pos = index.row();
    string oldTitle =  this->movieController->getMovieRepository().getMovies().get(pos).getTitle();

    string title = this->ui->titleLineEdit->text().toStdString();
    string genre = this->ui->genreLineEdit->text().toStdString();
    int year = stoi(this->ui->yearLineEdit->text().toStdString());
    int likes = stoi(this->ui->likesLineEdit->text().toStdString());
    string trailer = this->ui->trailerLineEDit->text().toStdString();

    //Compute the add operation
    this->movieController->update(oldTitle, title, genre, year, likes, trailer);

    //Emit an signal that announces a change in movies list
    emit moviesUpdated();
}

void MainWindow::eraseMovie() {
    QModelIndex index = this->ui->moviesListWidget->currentIndex();
    int pos = index.row();

    //Compute the add operation
    this->movieController->del( this->movieController->getMovieRepository().getMovies().get(pos).getTitle() );

    //Emit an signal that announces a change in movies list
    emit moviesUpdated();
}

void MainWindow::setAddWatchListTrue() {
    this->ui->addWatchListButton->setEnabled(true);
}

void MainWindow::setAddWatchListFalse() {
    this->ui->addWatchListButton->setEnabled(false);
}

void MainWindow::addWatchList() {
    //Get the name of the current Movie
    QString str = this->ui->currentMovieTitleTextBrowser->toPlainText();
    string crtMovieTitle = str.toStdString();
    cout<<crtMovieTitle;

    //Get the movie now
    int posFound = this->movieController->getMovieRepository().getMovies().find(Movie(crtMovieTitle));
    Movie movieFound = this->movieController->getMovieRepository().getMovies().get(posFound);

    WatchListItem watchListItem(crtMovieTitle, movieFound);
    this->movieController->getWatchListRepository()->add(watchListItem);

    emit watchListUpdated();
}

void MainWindow::eraseWatchList() {
    QModelIndex index = this->ui->watchListWidget->currentIndex();
    int pos = index.row() + 1;

    //Compute the add operation
    this->movieController->getWatchListRepository()->del( this->movieController->getWatchListRepository()->getWatchList().get(pos) );

    //Emit an signal that announces a change in movies list
    emit watchListUpdated();
}

void MainWindow::likeMovie() {

    //Increment the likes
    QString str = this->ui->currentMovieTitleTextBrowser->toPlainText();
    string crtMovieTitle = str.toStdString();
    this->movieController->incrementLikes(crtMovieTitle);


    //Let user to add movie to watch list
    this->setAddWatchListTrue();

    //Emit new change to watch list
    emit watchListUpdated();
    emit moviesUpdated();


}

void MainWindow::seeTrailerMovie() {

    cout<<"SEe trailer \n";
    QString str = this->ui->currentMovieTitleTextBrowser->toPlainText();
    string crtMovieTitle = str.toStdString();
    cout<<crtMovieTitle;

    int posFound = this->movieController->getMovieRepository().getMovies().find(Movie(crtMovieTitle));
    Movie movieFound = this->movieController->getMovieRepository().getMovies().get(posFound);

    string command (CHROME);
    command += " " + movieFound.getTrailer();
    system(command.c_str());

}


void MainWindow::populateMovieToUser() {
    Movie crtMovie = this->movieController->getByGenreByStep("", this->loopThroughMoviesPos);

    this->ui->currentMovieTitleTextBrowser->setText( QString::fromStdString( crtMovie.getTitle() ) );
}

void MainWindow::nextMovie() {
    this->loopThroughMoviesPos++;
    this->setAddWatchListFalse();
    emit currentMovieChanged();
}

void MainWindow::executeUndo() {

    cout<<"UNDO EXECUTED\n";
    if(this->movieController->undoList.size()) {
        //First add undo to redo
        this->movieController->redoList.push_back(this->movieController->undoList[this->movieController->undoList.size()-1] );

        int x = this->movieController->redoList.size();
        //Then execute the undo
        this->movieController->undoList.back()->executeUndo();
        this->movieController->undoList.pop_back();

        int y = this->movieController->redoList.size();
        emit moviesUpdated();
    }

}

void MainWindow::executeRedo() {
    cout<<this->movieController->redoList.size()<<"\n";
    cout<<"REDO EXECUTED\n";
    if(this->movieController->redoList.size()) {

        //Execute the redo
        this->movieController->redoList.back()->executeRedo();
        this->movieController->redoList.pop_back();
        emit moviesUpdated();
    }
}




