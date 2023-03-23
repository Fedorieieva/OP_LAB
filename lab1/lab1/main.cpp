#include <iostream>
#include "intro.h"
#include "choice1.h"
#include "choice2.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Invalid number of arguments. Usage: program_name [-mode FilePointer | -mode FileStream | -mode Intro]" << endl;
        return 1;
    }
    if (strcmp(argv[1], "-mode") != 0 || (strcmp(argv[2], "FilePointer") != 0 && strcmp(argv[2], "FileStream") != 0 && strcmp(argv[2], "Intro") != 0)) {
        cerr << "Invalid argument. Usage: program_name -mode [FilePointer | FileStream | Intro]";
        return 1;
    }

    if (strcmp(argv[2], "FilePointer") == 0) {
        choice1();
    }
    else if (strcmp(argv[2], "FileStream") == 0) {
        choice2();
    }
    else {
        intro();
    }

    return 0;
}
