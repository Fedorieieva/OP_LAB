#include "user.h"

template<typename T1, typename T2>
void user(HashTable<T1, T2>& ht) {

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
}