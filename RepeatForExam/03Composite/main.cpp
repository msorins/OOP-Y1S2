#include <iostream>
#include <fstream>
#include "Picture.h"
#include "Line.h"
#include "Rectangle.h"

using namespace std;

/*
 * http://www.bogotobogo.com/DesignPatterns/composite.php
 * https://www.youtube.com/watch?v=2HUnoKyC9l0
 */

int main() {
    Picture mainWindow("Main window");

    Line header("header");
    Line footer("footer");
    Picture content("content");
    Rectangle col1("col1");
    Rectangle col2("col2");

    content.add(&col1);
    content.add(&col2);

    mainWindow.add(&header);
    mainWindow.add(&content);
    mainWindow.add(&footer);

    mainWindow.draw();
    return 0;
}