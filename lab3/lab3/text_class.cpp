#include "text_class.h"

Text::Text() { content = ""; }

void Text::add_str(string str) {
    content += str;
}

void Text::print_text() {
    cout << content << endl;
}

double Text::consonant_percentage() {
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