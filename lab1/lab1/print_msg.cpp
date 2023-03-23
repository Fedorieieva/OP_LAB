#include "print_msg.h"

void print_msg(int num) {
    if (num != 0) {
        cout << endl << "-------------------------------------------------------------------------------------------------------------" << endl;
        if (num == 1) cout << "Initial file" << endl << endl;
        else if (num == 2) cout << "Changed file" << endl << endl;
        else cout << "Final file" << endl << endl;
    }
}