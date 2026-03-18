#ifndef ALPHABET_H
#define ALPHABET_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;



inline vector<string> alphabet = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I",
    "J", "K", "L", "M", "N", "O", "P", "Q", "R",
    "S", "T", "U", "V", "W", "X", "Y", "Z", "Å", "Ä", "Ö"
};

void ChooseLanguage() {
    int choice = 0;

    while (choice != 1 && choice != 2) {
        cout << "Choose alphabet\n";
        cout << "  1. English\n";
        cout << "  2. Swedish\n";
        cout << "Enter 1 or 2: ";
        cin >> choice;
    }

    if (choice == 1) {
        alphabet.resize(26);
        cout << "English alphabet selected!\n";
        
    } else {
        cout << "Swedish alphabet selected!\n";
    }
}

#endif
