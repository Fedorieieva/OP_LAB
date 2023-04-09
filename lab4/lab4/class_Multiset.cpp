#include "class_Multiset.h"

bool Multiset::in_multiset(const char& f) {
	return set.find(f) != string::npos;
}

bool Multiset::in_multiset(const string& other_multiset, const char& f) {
	return other_multiset.find(f) != string::npos;
}

string Multiset::unique(string s) {
	string u = "";
	for (int i = 0; i < s.length(); i++) {
		if (u.find(s[i]) == string::npos) {
			u += s[i];
		}
	}
	return u;
}

Multiset::Multiset() { set = ""; }

Multiset::Multiset(const string& s) {
	set = "";
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i]) && s[i] != ' ' && s[i] != '	')
			set += s[i];
	}
}

Multiset::Multiset(const Multiset& other) { set = other.set; }

string Multiset::Get_Multiset() { return set; }

Multiset Multiset::operator +(const Multiset& other) {
	string temp;
	temp = this->set + other.set;
	Multiset res;
	res.set = unique(temp);
	return res;
}

Multiset Multiset::operator *(const Multiset& other) {
	string temp;
	for (int i = 0; i < other.set.size(); i++) {
		if (in_multiset(other.set[i]))
			temp += other.set[i];
	}
	Multiset res;
	res.set = unique(temp);
	return res;
}

Multiset Multiset::operator -(const Multiset& other) {
	string temp;
	for (int i = 0; i < this->set.size(); i++) {
		if (!in_multiset(other.set, this->set[i]))
			temp += this->set[i];
	}
	Multiset res;
	res.set = unique(temp);
	return res;
}

ostream& operator <<(ostream& os, const Multiset& m) {
	os << "{";
	for (int i = 0; i < m.set.size(); i++) {
		os << "\"" << m.set.substr(i, 1) << "\"";
		if (i != m.set.size() - 1) {
			os << ", ";
		}
	}
	os << "}";
	return os;
}
