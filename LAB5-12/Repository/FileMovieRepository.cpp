//
// Created by Sorin Sebastian Mircea on 15/04/2017.
//

#include "FileMovieRepository.h"
#include "../List/DynamicArray.h"
#include "../List/STLVector.h"
#include "../Others/Exception.h"
#include "../Others/Iterator.h"
#include <fstream>
using namespace std;


template<class TVector>
void FileMovieRepository<TVector>::load() {
    Movie crtMovie;
    ifstream fin("../Files/shows.txt");

    //Load movies from file
    while(!fin.eof()) {
        fin >> crtMovie;

        if(crtMovie.getTitle().size() == 0)
            break;

        this->add(crtMovie);
    }
}

template<class TVector>
void FileMovieRepository<TVector>::save() {
    //Save movies to file
    ofstream fout("../Files/shows.txt");

    fout<<"x"<<"\n";

    Iterator< Movie> st1( this->movies.begin() );
    Iterator< Movie> dr1( this->movies.end() );


    for (Iterator< Movie > it=st1; it!=dr1; it++) {
        Movie crtMovie = *it;
        fout << crtMovie;
    }

    fout.close();

}

template class FileMovieRepository< DynamicArray<Movie> >;
template class FileMovieRepository< STLVector<Movie> >;
