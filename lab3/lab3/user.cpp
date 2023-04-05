#include "user.h"

void intro() {
    cout << "This programm develops a class that is an abstraction of text" << endl;
    cout << "and supports operations for adding a string to the text" << endl;
    cout << "and determining the percentage of consonants in the text." << endl;
    cout << "Creates an array of objects of this class." << endl;
    cout << "Adds some new lines to the texts." << endl;
    cout << "Determines the text with the highest percentage of consonants." << endl << endl;
}

void user() {
    void first_input(Text * txt, int initial, int& n);
    void append(Text * txt);
    void print_contents(Text * txt, int n);
    void print_precent(Text * txt, int n);
    int find_max_precent(Text * txt, int n);

    int initial_size = 10, num = 0;
    Text* text = new Text[initial_size];

    first_input(text, initial_size, num);
    print_contents(text, num);
    print_precent(text, num);
    int choice;
    cout << endl << endl << "Enter 1, if you want to append your texts: ";
    cin >> choice;

    if (choice == 1) {
        append(text);
        print_contents(text, num);
        print_precent(text, num);
    }
    
    int max_precent = find_max_precent(text, num);

    cout << endl << "The text with the highest consonant percentage:" << endl;
    cout << "Consonant percentage for text " << max_precent + 1 << ": " << text[max_precent].consonant_percentage() << "%" << endl;

    delete[] text;
}

void first_input(Text* txt, int initial, int& n) {
    int choice = 1;
    int max_size = initial;
    string str;

    do {
        if (n == max_size) {
            max_size *= 2;
            Text* new_text = new Text[max_size];

            for (int i = 0; i < n; i++) {
                new_text[i] = txt[i];
            }

            delete[] txt;
            txt = new_text;
        }

        cout << "Please enter your text " << n + 1 << ":" << endl;
        getline(cin, str);
        txt[n].add_str(str);
        n++;
        cout << "Enter 0, if you want to stop providing input: ";
        cin >> choice;
        cin.ignore();
        cout << endl;
    } while (choice != 0);
}

void append(Text* txt) {
    int choice = 1;
    string str;
    cout << endl << endl;
    int text_num = 0;
    do {
        cout << "Please enter the text number you want to append: ";
        cin >> text_num;
        cin.ignore();
        cout << "Please enter what you want to append:" << endl;
        getline(cin, str);
        txt[text_num - 1].add_str(str);
        cout << "Enter 0, if you want to stop providing input: ";
        cin >> choice;
        cout << endl;
    } while (choice != 0);
}

void print_contents(Text* txt, int n) {
    cout << "Here you can see the texts you have provided:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Text " << i + 1 << ": ";
        txt[i].print_text();
    }
}

void print_precent(Text* txt, int n) {
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << "Consonant percentage for text " << i + 1 << ": " << txt[i].consonant_percentage() << "%" << endl;
    }
}

int find_max_precent(Text* txt, int n) {
    int max_precent = 0;
    for (int i = 1; i < n; i++) {
        if (txt[i].consonant_percentage() > txt[i - 1].consonant_percentage()) {
            max_precent = i;
        }
    }
    return max_precent;
}
