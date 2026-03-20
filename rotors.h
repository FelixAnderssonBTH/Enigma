#ifndef ROTORS_H
#define ROTORS_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,vector<string>> EnglishRotors(){
    map<string, vector<string>> rotors;

    rotors["I"]   = {"E","K","M","F","L","G","D","Q","V","Z",
                      "N","T","O","W","Y","H","X","U","S","P",
                      "A","I","B","R","C","J"};

    rotors["II"]  = {"A","J","D","K","S","I","R","U","X","B",
                      "L","H","W","T","M","C","Q","G","Z","N",
                      "P","Y","F","V","O","E"};

    rotors["III"] = {"B","D","F","H","J","L","C","P","R","T",
                      "X","V","Z","N","Y","E","I","W","G","A",
                      "K","M","U","S","Q","O"};

    rotors["IV"]  = {"E","S","O","V","P","Z","J","A","Y","Q",
                      "U","I","R","H","X","L","N","F","T","G",
                      "K","D","C","M","W","B"};

    rotors["V"]   = {"V","Z","B","R","G","I","T","Y","U","P",
                      "S","D","N","H","L","X","A","W","M","J",
                      "Q","O","F","E","C","K"};

    return rotors;
}

map<string, vector<string>> SwedishRotors() {
    map<string, vector<string>> rotors;

    rotors["I"]   = {"F","L","N","G","M","H","E","R","W","Å",
                      "O","U","P","X","Z","I","Y","V","T","Q",
                      "B","J","C","S","D","K","Ä","Ö","A"};

    rotors["II"]  = {"Ö","D","H","K","Å","J","R","V","X","C",
                      "M","I","W","U","N","F","Ä","G","A","O",
                      "Q","Z","E","T","B","L","P","S","Y"};

    rotors["III"] = {"C","F","Ä","I","L","O","Å","R","U","X",
                      "B","E","H","Ö","K","N","Q","T","W","Z",
                      "D","G","J","M","P","S","V","Y","A"};

    rotors["IV"]  = {"Å","G","N","T","B","I","Ö","P","W","D",
                      "K","R","Y","F","Ä","M","S","Z","H","O",
                      "V","C","J","Q","X","E","L","A","U"};

    rotors["V"]   = {"J","Ä","R","C","L","U","E","Å","N","W",
                      "G","P","Y","I","Ö","B","K","T","D","M",
                      "V","F","O","X","H","Q","Z","A","S"};

    return rotors;
}

void printRotors(map<string, vector<string>>& rotors) {
    for (const auto& [name, wiring] : rotors) {
        cout << name << ": ";
        for (const auto& letter : wiring)
            cout << letter;
        cout << "\n";
    }
}

#endif
