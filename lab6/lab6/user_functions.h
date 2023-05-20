#pragma once
#include <iostream>
#include "HashTable.h"

using namespace std;

template<typename T1, typename T2>
void input_hash_table(HashTable<T1, T2>& table);

template<typename T1, typename T2>
void delete_element(HashTable<T1, T2>& table);

template<typename T1, typename T2>
void max_key_val(HashTable<T1, T2>& table);

template<typename T1, typename T2>
void get_key_value(HashTable<T1, T2>& table);

template<typename T1, typename T2>
void print_hash_table(HashTable<T1, T2>& table);
