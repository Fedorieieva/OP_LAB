#include <iostream>
#include "HashTable.h"
#include "HashTable.cpp"

using namespace std;

template<typename T1, typename T2>
void input_hash_table(HashTable<T1, T2>& table) {
    int count = 1;
    char choice = 'y';
    T1 key;
    T2 value;

    while (choice != 'n' && choice != 'N') {
        cout << endl << "Please enter your key for the " << count << " table: ";
        cin >> key;
        if (table.ispresent(key)) {
            cout << "Key already exists in the hash table. Please enter another key." << endl;
            continue;
        }
        cout << "And now please enter your value for the " << count << " table: ";
        cin >> value;
        cout << "Do you want to continue? [y/n]: ";
        cin >> choice;
        table.insert(key, value);
        count++;
    }

    cout << endl << "Here you can see the table you've provided:" << endl;
    table.printTable();
    cout << endl;
}

template<typename T1, typename T2>
void delete_element(HashTable<T1, T2>& table) {
    T1 key;
    cout << endl << "Here you can see your hash table:" << endl;
    table.printTable();
    cout << endl << "Please enter the key for the pair you want to remove from your hash table: ";
    cin >> key;
    table.remove(key);
    cout << endl << "Here you can see your hash table after deleting a pair:" << endl;
    table.printTable();
}

template<typename T1, typename T2>
void max_key_val(HashTable<T1, T2>& table) {
    T1 key = table.get_max_key();
    cout << "Here you can see the maximum key-value pair by key:" << endl;
    table.printPair(key);
}

template<typename T1, typename T2>
void get_key_value(HashTable<T1, T2>& table) {
    T1 key;
    cout << endl << "Here you can see your hash table:" << endl;
    table.printTable();
    cout << endl << "Please enter the key for the pair you want to find in your hash table: ";
    cin >> key;
    cout << endl << "Here you can see your key-value pair:" << endl;
    table.printPair(key);
}

template<typename T1, typename T2>
void print_hash_table(HashTable<T1, T2>& table) {
    cout << endl << "Here you can see your hash table:" << endl;
    table.printTable();
}

int main() {
    HashTable<int, string> ht;

    char choice;
    do {
        cout << endl << "1. Insert key-value pair" << endl;
        cout << "2. Print hash table" << endl;
        cout << "3. Delete key-value pair" << endl;
        cout << "4. Get key-value pair by key" << endl;
        cout << "5. Get maximum key-value pair by key" << endl;
        cout << "6. Get size of the hash table" << endl;
        cout << "7. Clear the hash table" << endl;
        cout << "8. Exit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            input_hash_table(ht);
            break;
        case '2':
            print_hash_table(ht);
            break;
        case '3':
            delete_element(ht);
            break;
        case '4':
            get_key_value(ht);
            break;
        case '5':
            max_key_val(ht);
            break;
        case '6':
            print_hash_table(ht);
            cout << endl << "Size of the hash table: " << ht.GetSize() << endl;
            break;
        case '7':
            ht.clear();
            cout << "Your hash table is empty now" << endl;
            break;
        case '8':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '8');

    return 0;
}
