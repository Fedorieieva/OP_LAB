#include "user.h"

void intro() {
	cout << "This programm creates a class Multiset for representing a set of characters," << endl;
	cout << "along with the required constructors, getters, and methods for determining" << endl;
	cout << "the membership of a given element in the set. It also includes overloaded" << endl;
	cout << "operators +, *, and - for finding the union, intersection, and difference of" << endl;
	cout << "sets, respectively. Additionally, there will be created three sets (A, B, C) using" << endl;
	cout << "different constructors and build set D = (A + B) - (C * B)" << endl;
}

void user() {
	void user_input(string & s);
	void output_set(Multiset & m);
	string str;
	char choice = 'N';

	user_input(str);
	Multiset A = (str == "" ? Multiset() : Multiset(str));

	user_input(str);
	Multiset B = (str == "" ? Multiset() : Multiset(str));

	user_input(str);
	Multiset C = (str == "" ? Multiset() : Multiset(str));

	Multiset K = A + B;
	Multiset Z = C * B;
	Multiset D = K - Z;

	cout << endl << "-------------------------------------------------------------------------------" << endl;
	cout << "Output using getters:" << endl << endl;
	cout << "Here you can see your sets:" << endl;
	cout << "A = ";
	output_set(A);
	cout << "B = ";
	output_set(B);
	cout << "C = ";
	output_set(C);

	cout << endl << "Do you want your output set to be sorted in alphabetical order [Y/N]? ";
	cin >> choice;

	if (choice == 'Y' || choice == 'y') 
		D.sort_set();

	cout << endl << "(A + B) - (C * B) = ";
	output_set(D);

	cout << endl << "-------------------------------------------------------------------------------" << endl;
	cout << "Output using an overloaded oparetor <<:" << endl << endl;
	cout << "Here you can see your sets:" << endl;
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "C = " << C << endl;

	cout << endl << "(A + B) - (C * B) = " << D << endl;
}

void user_input(string& s) {
	cout << endl << "Please enter charecters for one of three sets." << endl;
	cout << "NOTE 1: if you press Enter before providing any input, your set will be empty." << endl;
	cout << "NOTE 2: if you enter digits, they will not be present in your set." << endl;
	cout << "NOTE 3: if you enter duplicates, your input sets will containe only unique charachters." << endl;
	cout << "Input: ";
	getline(cin, s);
}

void output_set(Multiset& m) {
	string str = m.Get_Multiset();
	cout << "{";
	for (int i = 0; i < str.size(); i++) {
		cout << "\"" << str.substr(i, 1) << "\"";
		if (i != str.size() - 1) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}