#include <iostream>

using namespace std;

template<typename KeyType, typename ValueType>
class HashTable {
private:
    // HashNode class
    class Node {
    public:
        KeyType key;
        ValueType value;
        Node* next;

        Node(const KeyType& k, const ValueType& val) {
            key = k;
            value = val;
            next = nullptr;
        }
    };

    Node** table;  // Pointer to an array of hash node pointers
    int capacity;      // Current capacity of the hash table
    int size;          // Current size of the hash table

    // Resize the hash table to accommodate more elements
    void resize() {
        int newCapacity = capacity * 2;
        Node** newTable = new Node * [newCapacity] {}; // Allocate memory for the new hash-table
        for (int i = 0; i < capacity; i++) {
            Node* current = table[i];
            // Rehash all the nodes in the current chain
            while (current != nullptr) {
                Node* next = current->next;
                int newIndex = hashFunction(current->key);

                // Insert the node into the new hash table
                if (newTable[newIndex] == nullptr) {
                    newTable[newIndex] = current;
                    current->next = nullptr;
                }
                else {
                    Node* newCurrent = newTable[newIndex];

                    // Traverse to the end of the chain in the new table
                    while (newCurrent->next != nullptr) {
                        newCurrent = newCurrent->next;
                    }

                    // Insert the node at the end of the chain in the new table
                    newCurrent->next = current;
                    current->next = nullptr;
                }

                current = next;
            }
        }

        delete[] table;  // Free the memory of the old hash table
        table = newTable;  // Update the table pointer to the new hash table
        capacity = newCapacity;  // Update the capacity of the hash table
    }

public:
    class Iterator {
    private:
        HashTable* hash_table;
        int current_idx;
        Node* current_node;

    public:
        Iterator(HashTable* hash_t, int idx, Node* node) {
            hash_table = hash_t;
            current_idx = idx;
            current_node = node;
        }

        Iterator& operator++() {
            if (current_node != nullptr) {
                current_node = current_node->next;
                if (current_node == nullptr) {
                    current_idx++;
                    while (current_idx < hash_table->capacity && hash_table->table[current_idx] == nullptr) {
                        current_idx++;
                    }
                    if (current_idx < hash_table->capacity) {
                        current_node = hash_table->table[current_idx];
                    }
                }
            }
            return *this;
        }

        bool operator!=(const Iterator& other) {
            return current_node != other.current_node;
        }

        std::pair<const KeyType, ValueType> operator*() {
            return std::make_pair(current_node->key, current_node->value);
        }
    };

    HashTable() {
        capacity = 10;  // Set an initial capacity
        table = new Node * [capacity] {};  // Allocate memory for the hash table
        size = 0;  // Initialize size to
    }

    ~HashTable() {
        clear();  // Call the clear() function to delete all nodes in the hash table
        delete[] table;  // Free the memory allocated for the hash table array
    }

    int GetSize() { return size; }

    // Hash function
    int hashFunction(const KeyType& key) {
        // Convert the key to an integer hash value
        std::hash<KeyType> hasher;
        return hasher(key) % capacity;
    }

    // Insert a key-value pair into the hash table
    void insert(const KeyType& key, const ValueType& value) {
        // Check if the hash table needs to be resized
        if (size >= capacity) {
            resize();
        }

        int index = hashFunction(key);

        // Create a new hash node
        Node* newNode = new Node(key, value);

        // If the slot is empty, insert the node directly
        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            // Collision handling by chaining
            Node* current = table[index];

            // Traverse to the end of the chain
            while (current->next != nullptr) {
                current = current->next;
            }

            // Insert the new node at the end of the chain
            current->next = newNode;
        }

        size++;  // Increase the size of the hash table
    }

    // Retrieve the value associated with a key
    ValueType get_value(const KeyType& key) {
        int index = hashFunction(key);
        Node* current = table[index];

        // Traverse the chain to find the node with the matching key
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        // If key is not found, return a default value
        return ValueType();
    }

    KeyType get_max_key() {
        if (size == 0) {
            cout << "Hash table is empty" << endl;
        }
        auto it = begin();
        KeyType maxKey = (*it).first;
        ++it;
        while (it != end()) {
            if ((*it).first > maxKey) {
                maxKey = (*it).first;
            }
            ++it;
        }
        return maxKey;
    }

    // Remove a key-value pair from the hash table
    void remove(const KeyType& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        // Traverse the chain to find the node with the matching key
        while (current != nullptr) {
            if (current->key == key) {
                // If the node is the first in the chain
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    // Link the previous node to the next node
                    prev->next = current->next;
                }
                delete current;
                size--;  // Decrease the size of the hash table
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void clear() {
        for (int i = 0; i < capacity; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            table[i] = nullptr;
        }
        size = 0;
    }

    void printTable() {
        if (size == 0) {
            cout << "Hash table is empty" << endl;
            return;
        }
        else {
            for (auto it = begin(); it != end(); ++it) {
                cout << "Key: " << (*it).first << " Value: " << (*it).second << endl;
            }
        }
    }

    void printPair(const KeyType& key) {
        cout << "Key: " << key << " Value: " << get_value(key) << endl;
    }

    Iterator end() {
        return Iterator(this, capacity, nullptr);
    }

    Iterator begin() {
        int idx = 0;
        while (idx < capacity && table[idx] == nullptr) {
            idx++;
        }

        if (idx < capacity) {
            return Iterator(this, idx, table[idx]);
        }

        return end();
    }
};

template<typename T1, typename T2>
void input_hash_table(HashTable<T1, T2>& table) {
    int count = 1;
    char choice = 'y';
    T1 key;
    T2 value;

    while (choice != 'n' && choice != 'N') {
        cout << endl << "Please enter your key for the " << count << " table: ";
        cin >> key;
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
    cout << endl << "Here you can see your hash table:" <<endl;
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
