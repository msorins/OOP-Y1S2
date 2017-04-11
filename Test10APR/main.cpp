#include <iostream>
#include "ProjectController.h"
#include "UI.h"
#include "Tests.h"
using namespace std;

int main() {
    Tests test = Tests();

    ProjectController pc = ProjectController();
    UI ui = UI(pc);


}