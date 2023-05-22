#include <iostream>
#include "user.h"
#include "user.cpp"

using namespace std;

int main() {  
    char choice = '1';
    cout << "1. Create hashtable with int-string data types" << endl;
    cout << "2. Create hashtable with string-string data types" << endl;
    cout << "3. Create hashtable with string-int data types" << endl;
    cout << "4. Create hashtable with double-string data types" << endl;
    cout << "5. Create hashtable with string-double data types" << endl;
    cout << "6. Create hashtable with int-char data types" << endl;
    cout << "7. Create hashtable with char-int data types" << endl << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7');

    if (choice == '1') {
        HashTable<int, string> ht;
        user(ht);
    }
    else if (choice == '2') {
        HashTable<string, string> ht;
        user(ht);
    }
    else if (choice == '3') {
        HashTable<string, int> ht;
        user(ht);
    }
    else if (choice == '4') {
        HashTable<double, string> ht;
        user(ht);
    }
    else if (choice == '5') {
        HashTable<string, double> ht;
        user(ht);
    }
    else if (choice == '6') {
        HashTable<int, char> ht;
        user(ht);
    }
    else if (choice == '7') {
        HashTable<char, int> ht;
        user(ht);
    }
    
    return 0;
}
