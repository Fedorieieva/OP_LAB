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
	Multiset(const Multiset& other);
	string Get_Multiset();
	void sort_set();
	const Multiset operator +(const Multiset& other);
	const Multiset operator *(const Multiset& other);
	const Multiset operator -(const Multiset& other);
	friend ostream& operator <<(ostream& os, const Multiset& m);
};