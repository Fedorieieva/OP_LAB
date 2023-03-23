#include "train_schedule.h"

string Train_schedule::input_for_file() {	//get user input for the file
	int choice = 1;
	string filename;
	Train train;
	cout << "Please enter name of the file you want to create/open:" << endl;
	getline(cin, filename);
	do {
		train.schedule_input();	//get user input for the file into a structure
		write_to_file(filename, train);	//write input to a file
		cout << "Enter 0, if you want to stop providing input" << endl;
		cin >> choice;
	} while (choice != 0);
	cout << endl;
	return filename;	//return name of the file
}

void Train_schedule::read_file(const string& filename, string schedule) {	//read a binary file
	ifstream file(filename, ios::binary);
	if (!file.is_open()) {	//check for opening errors
		cout << "Error opening file" << endl;
		return;
	}

	file.seekg(0, ios::end);	//move pointer to the end of the file
	size_t count_strct = file.tellg() / sizeof(Train);	//calculate a number of Train structs in file
	file.seekg(0, ios::beg);	//return pointer to the begining of the file

	Train* trains = nullptr;
	try {
		trains = new Train[count_strct];	//allocate enough memory for structs
	}
	catch (const bad_alloc& e) {	//if allocation fails, it catches the bad_alloc exeption
		cout << "Error allocating memory: " << e.what() << endl;
		delete[] trains;
		file.close();	//in case of exeption it closes the file
		return;
	}

	print_title(schedule);
	for (size_t i = 0; i < count_strct && !file.eof(); i++) {	//read file into structs
		file.read(reinterpret_cast<char*>(&trains[i]), sizeof(Train));
		trains[i].print_schedule();	//print structs
	}
	cout << endl << endl;
	file.close();	//close file
	delete[] trains;	//free memory
}

void Train_schedule::winter_schedule(const string& filename) {	//create a new file with a different file input
	ifstream file(filename, ios::binary);
	if (!file.is_open()) {	//check for opening errors
		cout << "Error opening file" << endl;
		return;
	}

	file.seekg(0, ios::end);
	size_t count_strct = file.tellg() / sizeof(Train);	//calculate a number of Train structs in file
	file.seekg(0, ios::beg);

	Train* trains = nullptr;
	try {
		trains = new Train[count_strct];	//allocate enough memory for structs
	}
	catch (const bad_alloc& e) {	//if allocation fails, it catches the bad_alloc exeption
		cout << "Error allocating memory: " << e.what() << endl;
		delete[] trains;
		file.close();
		return;
	}

	for (size_t i = 0; i < count_strct && !file.eof(); i++) {	//read file into structs
		file.read(reinterpret_cast<char*>(&trains[i]), sizeof(Train));
		//reinterpret_cast is for casting the existing pointer to a char pointer
		//the read function expects a pointer to a char array
	}
	file.close();

	string time;
	string new_filename = "winter_" + filename;	//create new file
	ofstream winter_file(new_filename, ios::binary);
	if (!winter_file.is_open()) {	//check for opening errors
		cout << "Error opening file" << endl;
		delete[] trains;
		return;
	}

	for (size_t i = 0; i < count_strct; i++) {
		time = trains[i].departure_time.substr(0, 2);	//get a substring from trains[i].departure_time
		if (stoi(time) < 10 || stoi(time) >= 18) {	//check if a struct should be written into a new file
			winter_file.write(reinterpret_cast<char*>(&trains[i]), sizeof(Train));
		}
	}
	winter_file.close();
	delete[] trains;
	read_file(new_filename, "Winter Schedule");	//read the new file
}


void Train_schedule::write_to_file(const string& filename, const Train& train) {	//write to file
	ofstream file(filename, ios::app | ios::binary);
	if (!file.is_open()) {	//check for opening errors
		cout << "Error opening file" << endl;
		return;
	}
	file.write(reinterpret_cast<const char*>(&train), sizeof(Train));
	file.close();
}

void Train_schedule::print_title(const string& schedule) {	//print table title
	cout << schedule << endl;
}