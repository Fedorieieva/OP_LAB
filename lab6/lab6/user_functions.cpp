#include "user_functions.h"

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
