#include "file_stream.h"
#include "print_msg.h"

void input_to_file(string filename) {   //get user input into file
    ofstream file;
    file.open(filename, ofstream::app);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    string input;
    cout << "Enter text for the file (words should be separated by spaces only):" << endl;
    getline(cin, input);    //get input
    file << input + " ";    //write input to file
    file.close();
}

void write_to_file_change(string filename, string file_contents, int num) { //write changed user input to file
    ofstream file;
    if (num == 2) {
        file.open(filename);
    }
    else file.open(filename, ofstream::app);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    file << file_contents;
    file.close();
}

void read_file(string filename, string& contents, int num) {  //read and print file
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    print_msg(num);
    while (getline(file, contents)) {   //get file contents from file
        cout << contents;     // print file contents
    }
    file.close();
}

void find_substr(string& contents, string substr, int& idx, int num) {   //change substr to [substr-idx]
    if (num != 2) {
        idx = 1;
    }
    size_t pos = 0;
    string change;
    while ((pos = contents.find(substr, pos)) != string::npos) {    //find position of substr
        change = "[" + substr + "-" + to_string(idx) + "]"; //change substr
        contents.replace(pos, substr.length(), change); //replace substr with new substr
        idx++;  //increment index number
        pos += change.length(); //chnge cursor position
    }
}

void swap_substr_num(string& contents, string substr) {
    size_t pos = 0;
    int num = 1;
    string num_str = to_string(num);
    while ((pos = contents.find(substr + "-" + num_str)) != string::npos) {    //find position of substr
        num++;
        contents.replace(pos, substr.length() + 1 + num_str.length(), num_str + "-" + substr);  //replace substr-idx with idx-substr
        num_str = to_string(num);   //convert index number to string
        //pos += substr.length() + 1 + num_str.length();
    }
}