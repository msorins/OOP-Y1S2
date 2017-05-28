#include <iostream>
#include <QApplication>
#include "List/DynamicArray.h"
#include "UI/UI.h"
#include "Tests/Tests.h"
#include "List/STLVector.h"
#include "Others/Iterator.h"
#include "Others/Exception.h"
#include "UI/MainWindow.h"

using namespace std;


int main(int argc, char* argv[]) {
/*
    Tests tests;

    DynamicArray<int> a;
    a.push_back(1);
    a = a + 2;
    a = 3 + a;

    for(int i = 1; i<=a.size(); i++)
        cout<< a.get(i)<<" ";


    STLVector<int> da;


    int numbers[]={10,20,30,40,50};
    Iterator<int> from(numbers);
    Iterator<int> until(numbers+5);
    for (Iterator<int> it=from; it!=until; it++)
        std::cout << *it << ' ';
    std::cout << '\n';


    //Iterating over the Dynamic Array
    DynamicArray<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);

    Iterator< int > st(a.begin());
    Iterator< int > dr(a.end());

    for (Iterator< int > it=st; it!=dr; it++) {
        cout<<*it<<" ";
    }
    cout<<"\n";


    //Iterating over a repository
    MovieRepository<DynamicArray<Movie>> mp = MovieRepository<DynamicArray<Movie>>();
    mp.add(Movie("Sorinium1", "Horror", 2017, 10, "https://no"));
    mp.add(Movie("Sorinium2", "Horror", 2017, 10, "https://no"));
    mp.add(Movie("Sorinium3", "Horror", 2017, 10, "https://no"));
    mp.add(Movie("Sorinium4", "Horror", 2017, 10, "https://no"));
    mp.add(Movie("Sorinium5", "Horror", 2017, 10, "https://no"));
    mp.add(Movie("Sorinium6", "Horror", 2017, 10, "https://no"));


    Iterator< Movie> st1( mp.begin() );
    Iterator< Movie> dr1( mp.end() );

    for (Iterator< Movie > it=st1; it!=dr1; it++) {
        Movie m = *it;
        cout<<m.getTitle()<<" ";
    }

    std::cout << '\n';

 */




    while(true) {
        try {
            QApplication a(argc, argv);
            MainWindow w;
            w.show();
            a.exec();


        } catch(Exception ex) {
            std::cerr<<ex.what();
        }
    }



}