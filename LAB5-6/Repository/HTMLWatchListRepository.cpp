//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#include "HTMLWatchListRepository.h"
#include "../Others/Iterator.h"
#include <fstream>
using namespace std;

void HTMLWatchListRepository::saveCustom() {
    //Open the File
    ofstream fout("../Files/html-watch-list.html");

    fout<<"<!DOCTYPE html>\n";
    fout<<"<html>\n";
    fout<<"<head>\n";
    fout<<"~~~~ Watch List ~~~~"<<"\n";
    fout<<"</head>"<<"\n";
    fout<<"<body>"<<"\n";
    fout<<"<table border=1>"<<"\n";


    Iterator< WatchListItem > st1( this->getWatchList().begin() );
    Iterator< WatchListItem > dr1( this->getWatchList().end() );


    for (Iterator< WatchListItem > it=st1; it!=dr1; it++) {
        fout<<"<tr>"<<"\n";
        WatchListItem crt = *it;

        if(!crt.getTitle().size())
            continue;

        fout<<"<td>"<<crt.getMovie().getTitle()<<"</td>"<<"\n";
        fout<<"<td>"<<crt.getMovie().getGenre()<<"</td>"<<"\n";
        fout<<"<td>"<<crt.getMovie().getYear()<<"</td>"<<"\n";
        fout<<"<td>"<<crt.getMovie().getLikes()<<"</td>"<<"\n";
        fout<<"<td><a href=\""<<crt.getMovie().getTrailer()<<"\">Click</a></td>"<<"\n";

        fout<<"</tr>"<<"\n";
    }


    fout<<"</table>"<<"\n";
    fout<<"</body>"<<"\n";
    fout<<"</html>"<<"\n";
}
