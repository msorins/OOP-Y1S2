//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_UI_H
#define LAB5_6_UI_H
#include "../Controller/MovieController.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../Repository/FileMovieRepository.h"

#define STL  MemoryMovieRepository<STLVector<Movie>>
#define DYN  MemoryMovieRepository<DynamicArray<Movie>>
#define FSTL FileMovieRepository<STLVector<Movie>>
#define FDYN FileMovieRepository<DynamicArray<Movie>>

class UI {
public:
    MovieController< FSTL > movieController;
    string mode;

public:

    //Constructors
    UI();

    //Functionality
    void printAdminUI();
    void printUserUI();
    void printMainUI();

    void getAdminInput();
    void getUserInput();
    void getMainInput();

    bool checkCommand(int cmd);

    //Admin area
    void add();
    void del();
    void update();
    void list();

    //User area
    void userSeeMoviesByGenre();
    void userSeeWatchList();
    void userDeleteWatchList();

    void flushGetLine();

};


#endif //LAB5_6_UI_H
