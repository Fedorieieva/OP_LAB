#pragma once
#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void enter_filename_or_substr(char* str);
char* arr_input_ptr();
void write_file_ptr(char* filename, char* contents, int num);
char* read_file_ptr(char* filename);
void print_contents_file_ptr(char* contents, int num);
int count_substr_ptr(char* contents, char* substr);
int count_digits(int num);
int count_len_occ(char* contents, char* substr);
void change_substr(char* substr, char* new_substr, int num);
void swap_n_str(char* substr, char* new_substr, int num);
char* find_substr_ptr(char* contents, char* substr, int& j, int num);