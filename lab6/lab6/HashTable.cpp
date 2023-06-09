#include "HashTable.h"

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::Node::Node(const KeyType& k, const ValueType& val) {
    key = k;
    value = val;
    next = nullptr;
}

template<typename KeyType, typename ValueType>
unsigned int HashTable<KeyType, ValueType>::MurmurHash2(const KeyType* key, int len, int seed) {
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

template<typename KeyType, typename ValueType>
int HashTable<KeyType, ValueType>::hashFunction(const KeyType& key) {
    unsigned int hash = MurmurHash2(&key, sizeof(key), 0);
    return hash % capacity;
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::resize() {
    int new_capacity = capacity * 2;
    Node** new_table = new Node * [new_capacity] {};
    for (int i = 0; i < capacity; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->next;
            int new_index = hashFunction(current->key);

            if (new_table[new_index] == nullptr) {
                new_table[new_index] = current;
                current->next = nullptr;
            }
            else {
                Node* new_current = new_table[new_index];
                while (new_current->next != nullptr) {
                    new_current = new_current->next;
                }
                new_current->next = current;
                current->next = nullptr;
            }

            current = next;
        }
    }

    for (int i = 0; i < capacity; i++) {
        delete[] table[i];
    }
    delete[] table;
    table = new_table;
    capacity = new_capacity;
}

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::Iterator::Iterator(HashTable* hash_t, int idx, Node* node) {
    hash_table = hash_t;
    current_idx = idx;
    current_node = node;
}

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::Iterator::Pair::Pair(const KeyType& k, ValueType& val) {
    key = k;
    value = val;
}

template<typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator& HashTable<KeyType, ValueType>::Iterator::operator++() {
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

template<typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::Iterator::operator!=(const Iterator& other) {
    return current_node != other.current_node;
}

template<typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator::Pair HashTable<KeyType, ValueType>::Iterator::operator*() {
    return Pair(current_node->key, current_node->value);
}

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable() {
    capacity = 10;
    table = new Node * [capacity] {};
    size = 0;
}

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable() {
    clear();
    for (int i = 0; i < capacity; i++) {
        delete[] table[i];
    }
    delete[] table;
}

template<typename KeyType, typename ValueType>
int HashTable<KeyType, ValueType>::GetSize() {
    return size;
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    if (size >= capacity) {
        resize();
    }

    int index = hashFunction(key);

    Node* new_node = new Node(key, value);

    if (table[index] == nullptr) {
        table[index] = new_node;
    }
    else {
        Node* current = table[index];

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new_node;
    }

    size++;
}

template<typename KeyType, typename ValueType>
ValueType HashTable<KeyType, ValueType>::GetValue(const KeyType& key) {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    throw runtime_error("There is no such key-value pair in this hashtable");
}

template<typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::ispresent(const KeyType& key) {
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

template<typename KeyType, typename ValueType>
KeyType HashTable<KeyType, ValueType>::GetMaxKey() {
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

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType& key) {
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
        }
        prev = current;
        current = current->next;
    }
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::clear() {
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

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::printTable() {
    if (size == 0) {
        cout << "Hash table is empty" << endl;
    }
    else {
        for (auto it = begin(); it != end(); ++it) {
            cout << "Key: " << (*it).key << " - Value: " << (*it).value << endl;
        }
    }
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::printPair(const KeyType& key) {
    try {
        cout << "Key: " << key << " - Value: " << GetValue(key) << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

template<typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator HashTable<KeyType, ValueType>::begin() {
    int index = 0;
    while (index < capacity && table[index] == nullptr) {
        index++;
    }
    if (index < capacity) {
        return Iterator(this, index, table[index]);
    }
    return end();
}

template<typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator HashTable<KeyType, ValueType>::end() {
    return Iterator(this, capacity, nullptr);
}

