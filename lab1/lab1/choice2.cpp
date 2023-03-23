#include "choice2.h"
#include "file_stream.h"
#include "print_msg.h"

void choice2() {        //FileStream mode
    int ch, idx = 1;
    string path, path2, path3, substr, text, append;
    cout << "Please enter name of the file you want to create/open:" << endl;
    getline(cin, path); //get filename

    path2 = "file1_" + path;  //cancatenate for temp file
    path3 = "file2_" + path;

    input_to_file(path);   //get input into file
    cout << "Please enter the substring you want to find in your file:" << endl;
    getline(cin, substr); //get substr
    read_file(path, text, 1);  //read and print file

    find_substr(text, substr, idx, 1);   //change substr to [substr-idx]
    write_to_file_change(path2, text, 1);   //write new contents to file
    read_file(path2, text, 2);  //read and print file

    swap_substr_num(text, substr);    //find and change substr [idx-substr]
    write_to_file_change(path3, text, 1);   //write new contents to file
    read_file(path3, text, 3);  //read and print file

    cout << endl << endl << "If you want to append your file, enter 1, if not please enter 2" << endl;
    cin >> ch;

    if (ch == 1) {  //if you want to append file
        cin.ignore();
        cout << "Enter text for the file (words should be separated by spaces only):" << endl;
        getline(cin, append);   //get input for file

        read_file(path, text, 1);  //read and print file
        cout << append; //print appended contents

        find_substr(append, substr, idx, 2);   //change substr to [substr-idx]
        write_to_file_change(path2, append, 1);   //write new contents to file
        read_file(path2, append, 2);  //read and print file

        swap_substr_num(append, substr);    //find and change substr [idx-substr]
        write_to_file_change(path3, append, 2);   //write new contents to file
        read_file(path3, append, 3);  //read and print file
    }
    if (remove(path.c_str()) != 0 || remove(path2.c_str()) != 0) {     //delete file
        cout << endl << "Error deleting file" << endl;
    }
    if (rename(path3.c_str(), path.c_str()) != 0) { //rename temp file
        cout << endl << "Error renaming file" << endl;
    }
}