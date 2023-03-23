#include "intro.h"

void intro() {
    cout << endl << "In this program you can create a txt file, in which you will enter words seperated by comas only." << endl;
    cout << "The task of this program is to find and reshape a substring you entered in created txt file." << endl;
    cout << "For example you entered text: time timeless sleep food continue." << endl;
    cout << "And you entered a substring: ti." << endl;
    cout << "The program will create two extra files, both of which will contain the result of reshaping the text you entered." << endl;
    cout << "Result 1: [ti-1]me [ti-2]meless sleep food con[ti-3]nue." << endl;
    cout << "Result 2: [1-ti]me [2-ti]meless sleep food con[3-ti]nue." << endl;
    cout << "This program works in two modes:" << endl;
    cout << "1) FilePointer" << endl;
    cout << "2) FileStream" << endl;
    cout << "print [-mode FilePointer | -mode FileStream | -mode Intro]" << endl << endl;
}