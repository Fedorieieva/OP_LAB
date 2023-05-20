#pragma once
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

        Node(const KeyType& k, const ValueType& val);
    };

    unsigned int MurmurHash2(const void* key, int len, unsigned int seed);
    int hashFunction(const KeyType& key);
    void resize();

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

            Entry(const KeyType& k, ValueType& val);
        };

        Iterator(HashTable* hash_t, int idx, Node* node);
        Iterator& operator++();
        bool operator!=(const Iterator& other);
        Entry operator*();
    };

    HashTable();
    ~HashTable();
    int GetSize();
    void insert(const KeyType& key, const ValueType& value);
    ValueType get_value(const KeyType& key);
    bool ispresent(const KeyType& key);
    KeyType get_max_key();
    void remove(const KeyType& key);
    void clear();
    void printTable();
    void printPair(const KeyType& key);
    Iterator end();
    Iterator begin();
};