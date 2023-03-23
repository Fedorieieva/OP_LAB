#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

void input_to_file(string filename);
void write_to_file_change(string filename, string file_contents, int num);
void read_file(string filename, string& contents, int n);
void find_substr(string& contents, string substr, int& idx, int num);
void swap_substr_num(string& contents, string substr);