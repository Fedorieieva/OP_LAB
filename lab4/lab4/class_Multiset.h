#pragma once
#include <iostream>
#include <string>

using namespace std;

class Multiset {
private:
	string set;

	bool in_multiset(const char& f);
	bool in_multiset(const string& other_multiset, const char& f);
	string unique(string s);

public:
	Multiset();
	Multiset(const string& s);
	string Get_Multiset();
	Multiset operator +(const Multiset& other);
	Multiset operator *(const Multiset& other);
	Multiset operator -(const Multiset& other);
	friend ostream& operator <<(ostream& os, const Multiset& m);
};