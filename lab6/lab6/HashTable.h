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

    unsigned int MurmurHash2(const KeyType* key, int len, int seed);
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
        struct Pair {
            const KeyType& key;
            ValueType& value;

            Pair(const KeyType& k, ValueType& val);
        };

        Iterator(HashTable* hash_t, int idx, Node* node);
        Iterator& operator++();
        bool operator!=(const Iterator& other);
        Pair operator*();
    };

    HashTable();
    ~HashTable();
    int GetSize();
    void insert(const KeyType& key, const ValueType& value);
    ValueType GetValue(const KeyType& key);
    bool ispresent(const KeyType& key);
    KeyType GetMaxKey();
    void remove(const KeyType& key);
    void clear();
    void printTable();
    void printPair(const KeyType& key);
    Iterator end();
    Iterator begin();
};