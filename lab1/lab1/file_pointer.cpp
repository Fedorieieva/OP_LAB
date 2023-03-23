#include "file_pointer.h"
#include "print_msg.h"

void enter_filename_or_substr(char* str) {  //get name of the file/substring from user
    int size = 0;
    char c;
    while (cin.get(c)) {
        if (c == '\n') break;
        str[size] = c;
        size++;
    }
    str[size] = '\0';
}

char* arr_input_ptr() { //get text from user for the file
    int capacity = 256, size = 0;
    char* arr = (char*)calloc(capacity, sizeof(char));
    char c;
    cout << "Enter text for the file (words should be separated by spaces only):" << endl;
    while (cin.get(c)) {
        if (c == '\n') break;
        if (size == capacity) { //allocate more memory if there is not enough
            capacity *= 2;
            char* temp = (char*)calloc(capacity, sizeof(char));
            for (int i = 0; i < size; i++) {    //write input into a new array
                temp[i] = arr[i];
            }
            free(arr);
            arr = temp;
        }
        arr[size] = c;
        size++;
    }
    arr[size] = '\0';
    return arr;
}

void write_file_ptr(char* filename, char* contents, int num) {
    FILE* file;
    if (num == 1) {
        fopen_s(&file, filename, "a+");  //open file in append mode
    }
    else {
        fopen_s(&file, filename, "w");  //open file in writing mode
    }
    if (file == nullptr) {
        cerr << "Error opening this file" << endl;
        return;
    }
    fputs(contents, file);  //writing to file
    fputs(" ", file);
    if (fclose(file) == EOF) {
        cerr << "Error closing file" << endl;
        return;
    }
}

char* read_file_ptr(char* filename) {
    FILE* file;
    fopen_s(&file, filename, "r");  //open file in reading mode
    if (file == nullptr) {
        cerr << "Error opening this file" << endl;
        return nullptr;
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);    //get number of characters in file
    fseek(file, 0, SEEK_SET);
    char* arr = (char*)calloc(file_size, sizeof(char)); //allocate memory for file contents
    fread(arr, sizeof(char), file_size, file);
    arr[file_size] = '\0';
    if (ferror(file)) {
        cerr << "Error reading from file" << endl;
        return nullptr;
    }
    if (fclose(file) == EOF) {
        cerr << "Error closing file" << endl;
        return nullptr;
    }
    return arr;
}

void print_contents_file_ptr(char* contents, int num) { //print file contents
    print_msg(num); //print masg initial/changed/final file
    for (int i = 0; i < strlen(contents); i++) {
        cout << contents[i];
    }
}

int count_substr_ptr(char* contents, char* substr) {    //count number of substrings that occur in file
    int j, count, count2 = 0;
    for (int i = 0; i < strlen(contents);) {
        j = 0;
        count = 0;
        while (contents[i] == substr[j]) {
            count++;    //count number of characters found in file contents that are equal to substr
            i++;
            j++;
        }
        if (count == strlen(substr)) {  //if number of characters found in file contents that 
            count2++;   //are equal to substr == len(substr), count occurrence of substr++
            count = 0;
        }
        else i++;
    }
    return count2;
}

int count_digits(int num) { //count number of digits in an index number 
    int digits = 0;
    while (num != 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

int count_len_occ(char* contents, char* substr) {   //count total number of characters for all indexes
    int len = 0;
    int num = count_substr_ptr(contents, substr);
    for (int i = 1; i <= num; i++) {
        len += count_digits(i);
    }
    return len;
}

void change_substr(char* substr, char* new_substr, int num) {   //change substr to [substr-idx]
    char* str_num = (char*)calloc(count_digits(num) + 1, sizeof(char)); //allocate memory for idndex number
    new_substr[0] = '[';
    int i = 1;
    while (i <= strlen(substr) + 1) {
        if (i == strlen(substr) + 1) {
            new_substr[i] = '-';
        }
        else {
            new_substr[i] = substr[i - 1];  //write substr into a new substr
        }
        i++;
    }
    sprintf_s(str_num, count_digits(num) + 1, "%d", num);   //write idx number into a char array
    for (int j = 0; j < count_digits(num); j++) {
        new_substr[i] = str_num[j]; //write idx number into a new substr
        i++;
    }
    new_substr[i] = ']';
    new_substr[i + 1] = '\0';
    free(str_num);
}

void swap_n_str(char* substr, char* new_substr, int num) {  //swap substr and idx num [idx-substr]
    int k = 0, num_size = count_digits(num);
    char* str_num = (char*)calloc(num_size + 1, sizeof(char));  //allocate memory for idndex number
    sprintf_s(str_num, count_digits(num) + 1, "%d", num);   //write idx number into a char array
    for (int i = 0; i < num_size; i++) {
        new_substr[i] = str_num[i]; //write idx number into a new substr
    }
    new_substr[num_size] = '-';
    for (int i = num_size + 1; i <= strlen(substr) + num_size; i++) {
        if (i == strlen(substr) + num_size) {
            new_substr[i + 1] = '\0';
        }
        new_substr[i] = substr[k];  //write substr into a new substr
        k++;
    }
    free(str_num);
}

char* find_substr_ptr(char* contents, char* substr, int& count, int num) {  //change file contents
    if (num != 3 && num != 4) {
        count = 1;
    }
    else if (num == 4) {
        count--;
    }
    size_t new_len_sub = ((strlen(substr) + 3) * count_substr_ptr(contents, substr)) + count_len_occ(contents, substr); //count number of characters for all new substrings
    size_t change_con_len = strlen(contents) + new_len_sub; //count number of characters that will be in new file contents
    size_t i = 0, j = 0;
    char* arr = (char*)calloc(change_con_len + 2, sizeof(char));    //allocate memory for new file contents
    char* new_substr = (char*)calloc((strlen(substr) + count_len_occ(contents, substr) + 4), sizeof(char)); //allocate memory for new substring
    while (i < strlen(contents)) {  //go through all contents
        if (strstr(&contents[i], substr) == &contents[i]) { //if substr found in file contents
            if (num == 1 || num == 3) {
                change_substr(substr, new_substr, count);   //new substr = substr [substr-idx]
                i += strlen(substr);    //add a number of characters in substr
            }
            else if (num == 2 || num == 4) {
                swap_n_str(substr, new_substr, count);   //new substr = substr [idx-substr]
                i += strlen(substr) + count_digits(count) + 1;  //add a number of characters in substr + idx.len + 1 (-)
            }
            strcpy_s(&arr[j], change_con_len + 1, new_substr); //copy new substr to new file contents
            j += strlen(new_substr);    //add a number of characters in new substr
            count++;
        }
        else {
            arr[j] = contents[i];   //write file contents to new file contents
            i++;
            j++;
        }
    }
    free(new_substr);
    arr[j] = '\0';
    return arr;
}