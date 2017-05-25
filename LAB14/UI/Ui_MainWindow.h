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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QListWidget *moviesListWidget;
    QLineEdit *titleLineEdit;
    QLineEdit *genreLineEdit;
    QLineEdit *yearLineEdit;
    QLineEdit *likesLineEdit;
    QLineEdit *trailerLineEDit;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *eraseButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *watchListWidget;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *seeTrailerButton;
    QPushButton *likeButton;
    QTextBrowser *currentMovieTitleTextBrowser;
    QPushButton *nextButton;
    QPushButton *addWatchListButton;
    QPushButton *eraseWatchListButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *pieVerticalLayout;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(994, 1000);
        MainWindow->setMaximumSize(QSize(1000, 1000));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(460, 0, 51, 611));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        moviesListWidget = new QListWidget(centralWidget);
        moviesListWidget->setObjectName(QStringLiteral("moviesListWidget"));
        moviesListWidget->setGeometry(QRect(90, 20, 311, 271));
        titleLineEdit = new QLineEdit(centralWidget);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));
        titleLineEdit->setGeometry(QRect(90, 320, 113, 21));
        genreLineEdit = new QLineEdit(centralWidget);
        genreLineEdit->setObjectName(QStringLiteral("genreLineEdit"));
        genreLineEdit->setGeometry(QRect(290, 320, 113, 21));
        yearLineEdit = new QLineEdit(centralWidget);
        yearLineEdit->setObjectName(QStringLiteral("yearLineEdit"));
        yearLineEdit->setGeometry(QRect(90, 370, 113, 21));
        yearLineEdit->setToolTipDuration(1);
        likesLineEdit = new QLineEdit(centralWidget);
        likesLineEdit->setObjectName(QStringLiteral("likesLineEdit"));
        likesLineEdit->setGeometry(QRect(290, 370, 113, 21));
        trailerLineEDit = new QLineEdit(centralWidget);
        trailerLineEDit->setObjectName(QStringLiteral("trailerLineEDit"));
        trailerLineEDit->setGeometry(QRect(90, 420, 311, 21));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(90, 460, 311, 32));
        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(90, 500, 311, 32));
        eraseButton = new QPushButton(centralWidget);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));
        eraseButton->setGeometry(QRect(90, 550, 311, 32));
        eraseButton->setAutoDefault(false);
        eraseButton->setFlat(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 51, 61));
        QFont font;
        font.setPointSize(60);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 160, 51, 61));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 240, 51, 61));
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 330, 51, 61));
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 420, 51, 61));
        label_5->setFont(font);
        watchListWidget = new QListWidget(centralWidget);
        watchListWidget->setObjectName(QStringLiteral("watchListWidget"));
        watchListWidget->setGeometry(QRect(570, 20, 391, 431));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(500, 110, 51, 61));
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(500, 200, 51, 61));
        label_7->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(500, 290, 51, 61));
        label_8->setFont(font);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(500, 380, 51, 61));
        label_9->setFont(font);
        seeTrailerButton = new QPushButton(centralWidget);
        seeTrailerButton->setObjectName(QStringLiteral("seeTrailerButton"));
        seeTrailerButton->setGeometry(QRect(570, 550, 121, 32));
        likeButton = new QPushButton(centralWidget);
        likeButton->setObjectName(QStringLiteral("likeButton"));
        likeButton->setGeometry(QRect(700, 550, 131, 32));
        currentMovieTitleTextBrowser = new QTextBrowser(centralWidget);
        currentMovieTitleTextBrowser->setObjectName(QStringLiteral("currentMovieTitleTextBrowser"));
        currentMovieTitleTextBrowser->setGeometry(QRect(570, 490, 381, 31));
        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(840, 550, 121, 32));
        addWatchListButton = new QPushButton(centralWidget);
        addWatchListButton->setObjectName(QStringLiteral("addWatchListButton"));
        addWatchListButton->setGeometry(QRect(570, 580, 191, 32));
        eraseWatchListButton = new QPushButton(centralWidget);
        eraseWatchListButton->setObjectName(QStringLiteral("eraseWatchListButton"));
        eraseWatchListButton->setGeometry(QRect(770, 580, 191, 32));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 639, 981, 301));
        pieVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        pieVerticalLayout->setSpacing(6);
        pieVerticalLayout->setContentsMargins(11, 11, 11, 11);
        pieVerticalLayout->setObjectName(QStringLiteral("pieVerticalLayout"));
        pieVerticalLayout->setContentsMargins(0, 0, 0, 0);
        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(10, 580, 231, 61));
        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(240, 580, 231, 61));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 994, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        eraseButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        titleLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Title", Q_NULLPTR));
        genreLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Genre", Q_NULLPTR));
        yearLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Year", Q_NULLPTR));
        likesLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Likes", Q_NULLPTR));
        trailerLineEDit->setPlaceholderText(QApplication::translate("MainWindow", "Trailer Link", Q_NULLPTR));
        addButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        editButton->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        eraseButton->setText(QApplication::translate("MainWindow", "Erase", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "M", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "I", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "U", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "S", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        seeTrailerButton->setText(QApplication::translate("MainWindow", "SEE TRAILER", Q_NULLPTR));
        likeButton->setText(QApplication::translate("MainWindow", "Like", Q_NULLPTR));
        nextButton->setText(QApplication::translate("MainWindow", "NEXT", Q_NULLPTR));
        addWatchListButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        eraseWatchListButton->setText(QApplication::translate("MainWindow", "Erase", Q_NULLPTR));
        undoButton->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        redoButton->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
