#include <iostream>
#include <string>

using namespace std;

class Text {
    string content;

public:
    Text() { content = ""; }

    void add_str(string str) {
        content += str;
    }

    void print_text() {
        cout << content << endl;
    }

    void print_concsonant(int& num) {
        cout << "Consonant percentage for text " << num + 1 << ": " << consonant_percentage() << "%" << endl;
    }

private:
    double consonant_percentage() {
        int total = 0, consonants = 0;

        for (char c : content) {
            if (isalpha(c)) {
                total++;
                if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
                    c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
                    consonants++;
                }
            }
        }

        if (total == 0) return 0.0;
        return (double)consonants / (double)total * 100.0;
    }
};

void user() {
    int initial_size = 2, num = 0, choice = 1;
    int max_size = initial_size;
    string str;
    Text* text = new Text[initial_size];

    do {
        if (num == max_size) {
            max_size *= 2;
            Text* new_text = new Text[max_size];

            for (int i = 0; i < num; i++) {
                new_text[i] = text[i];
            }

            delete[] text;
            text = new_text;
        }

        cout << "Please enter your text " << num + 1 << ":" << endl;
        getline(cin, str);
        text[num].add_str(str);
        num++;
        cout << "Enter 0, if you want to stop providing input: ";
        cin >> choice;
        cin.ignore();
        cout << endl;
    } while (choice != 0);

    cout << endl << endl;
    for (int i = 0; i < num; i++) {
        text[i].print_concsonant(i);
    }

    cout << endl << endl;
    int text_num = 0;
    do {
        cout << "Please enter the text number you want to append: ";
        cin >> text_num;
        cin.ignore();
        cout << "Please enter what you want to append:" << endl;
        getline(cin, str);
        text[text_num - 1].add_str(str);
        cout << "Enter 0, if you want to stop providing input: ";
        cin >> choice;
        cout << endl;
    } while (choice != 0);

    cout << endl << "Here you can see the texts you have provided:" << endl << endl;
    for (int i = 0; i < num; i++) {
        cout << "Text " << i + 1 << ": ";
        text[i].print_text();
    }

    cout << endl;
    for (int i = 0; i < num; i++) {
        text[i].print_concsonant(i);
    }

    delete[] text;
}

int main() {
    user();
    return 0;
}