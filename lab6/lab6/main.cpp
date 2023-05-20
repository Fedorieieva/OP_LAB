#include <iostream>

using namespace std;

template<typename KeyType, typename ValueType>
class HashTable {
private:
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

    unsigned int MurmurHash2(const void* key, int len, unsigned int seed) {
        const unsigned int m = 0x5bd1e995;
        const int r = 24;

        unsigned int h = seed ^ len;

        const unsigned char* data = (const unsigned char*)key;

        while (len >= 4) {
            unsigned int k = *(unsigned int*)data;

            k *= m;
            k ^= k >> r;
            k *= m;

            h *= m;
            h ^= k;

            data += 4;
            len -= 4;
        }

        switch (len) {
        case 3:
            h ^= data[2] << 16;
        case 2:
            h ^= data[1] << 8;
        case 1:
            h ^= data[0];
            h *= m;
        };

        h ^= h >> 13;
        h *= m;
        h ^= h >> 15;

        return h;
    }

    void resize() {
        int newCapacity = capacity * 2;
        Node** newTable = new Node * [newCapacity] {};
        for (int i = 0; i < capacity; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* next = current->next;
                int newIndex = hashFunction(current->key);

                if (newTable[newIndex] == nullptr) {
                    newTable[newIndex] = current;
                    current->next = nullptr;
                }
                else {
                    Node* newCurrent = newTable[newIndex];

                    while (newCurrent->next != nullptr) {
                        newCurrent = newCurrent->next;
                    }

                    newCurrent->next = current;
                    current->next = nullptr;
                }

                current = next;
            }
        }

        delete[] table;
        table = newTable;
        capacity = newCapacity;
    }

    Node** table;
    int capacity;
    int size;

public:
    class Iterator {
    private:
        HashTable* hash_table;
        int current_idx;
        Node* current_node;

    public:
        struct Entry {
            const KeyType& key;
            ValueType& value;

            Entry(const KeyType& k, ValueType& val) : key(k), value(val) {}
        };

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

        Entry operator*() {
            return Entry(current_node->key, current_node->value);
        }
    };

    HashTable() {
        capacity = 10;
        table = new Node * [capacity] {};
        size = 0;
    }

    ~HashTable() {
        clear();
        delete[] table;
    }

    int GetSize() { return size; }

    int hashFunction(const KeyType& key) {
        unsigned int hash = MurmurHash2(&key, sizeof(key), 0);
        return hash % capacity;
    }

    void insert(const KeyType& key, const ValueType& value) {
        if (size >= capacity) {
            resize();
        }

        int index = hashFunction(key);

        Node* newNode = new Node(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            Node* current = table[index];

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
        }

        size++;
    }

    ValueType get_value(const KeyType& key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        return ValueType();
    }

    bool ispresent(const KeyType& key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    KeyType get_max_key() {
        if (size == 0) {
            cout << "Hash table is empty" << endl;
        }
        auto it = begin();
        KeyType maxKey = (*it).key;
        ++it;
        while (it != end()) {
            if ((*it).key > maxKey) {
                maxKey = (*it).key;
            }
            ++it;
        }
        return maxKey;
    }

    void remove(const KeyType& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                size--;
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
                cout << "Key: " << (*it).key << " - Value: " << (*it).value << endl;
            }
        }
    }

    void printPair(const KeyType& key) {
        cout << "Key: " << key << " - Value: " << get_value(key) << endl;
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
