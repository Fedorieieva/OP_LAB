#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Train {
	string direction;
	string departure_time;
	string arrival_time;
	string train_number;

	void schedule_input() {	//user input into a struct
		cout << "Enter train number: ";
		cin >> train_number;
		cout << "Enter direction: ";
		cin >> direction;
		cout << "Enter departure time (hh:mm): ";
		cin >> departure_time;
		cout << "Enter arrival time (hh:mm): ";
		cin >> arrival_time;
	}

	void print_schedule() {	//struct output in a table form
		cout << setw(10) << left << train_number;
		cout << setw(30) << left << direction;
		cout << setw(20) << left << departure_time;
		cout << setw(20) << left << arrival_time << endl;
	}
};