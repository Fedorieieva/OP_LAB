#include "choice1.h"
#include "file_pointer.h"
#include "print_msg.h"

void choice1() {        //FilePointer mode
    char filename[25];
    char filename3[45] = "file3_";
    char substr_ptr[10];
    int count = 0, ch;

    cout << "Please enter name of the file you want to create/open:" << endl;
    enter_filename_or_substr(filename); //get filename
    strcat_s(filename3, 45, filename);  //cancatenate for temp file
    char* contents = arr_input_ptr();   //get input for file
    cout << "Please enter the substring you want to find in your file:" << endl;
    enter_filename_or_substr(substr_ptr); //get substr
    write_file_ptr(filename, contents, 1);  //write input to file

    char* file_contents = read_file_ptr(filename);  //read file
    print_contents_file_ptr(file_contents, 1);  //print file contents

    char* file_contents2 = find_substr_ptr(file_contents, substr_ptr, count, 1);    //find and change substr [substr-idx]
    print_contents_file_ptr(file_contents2, 2);  //print file contents

    char* file_contents3 = find_substr_ptr(file_contents2, substr_ptr, count, 2);    //find and change substr [idx-substr]
    print_contents_file_ptr(file_contents3, 3);  //print file contents
    write_file_ptr(filename3, file_contents3, 2);  //write new file contents to file

    if (remove(filename) != 0) {    //delete file
        cout << "Error deleting file" << endl;
    }
    if (rename(filename3, filename) != 0) { //rename temp file
        cout << "Error renaming file" << endl;
    }

    cout << endl << "If you want to append your file, enter 1, if not please enter 2" << endl;
    cin >> ch;
    if (ch == 1) {  //if you want to append file
        cin.ignore();
        char* contents2 = arr_input_ptr();   //get input for file
        print_contents_file_ptr(file_contents, 1);  //print file contents
        print_contents_file_ptr(contents2, 0);  //print appended file contents

        char* contents3 = find_substr_ptr(contents2, substr_ptr, count, 3);    //find and change substr [substr-idx]
        print_contents_file_ptr(file_contents2, 2);  //print file contents
        print_contents_file_ptr(contents3, 0);  //print appended file contents

        char* contents4 = find_substr_ptr(contents3, substr_ptr, count, 4);    //find and change substr [idx-substr]
        print_contents_file_ptr(file_contents3, 3);  //print file contents
        print_contents_file_ptr(contents4, 0);  //print appended file contents
        write_file_ptr(filename, contents4, 1);  //write input to file

    }
}