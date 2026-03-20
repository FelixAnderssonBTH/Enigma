#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "rotors.h"
#include "language.h"

using namespace std;

map<string, string> wiring; 


bool inAlphabet(const string& character) {
    return find(alphabet.begin(), alphabet.end(), character) != alphabet.end();
}




string toUpper(string& s){
    if (s == "å") return "Å";
    if (s == "ä") return "Ä";
    if (s == "ö") return "Ö";
    string s_upper = s;
    s_upper[0] = toupper(s_upper[0]);
    return s_upper;
}

bool controll(string& x, string& y){
    
    if(x == y){
      cout<< "Cant pair with same letter\n";
      return false;
    
    }for (const auto& [key, val] : wiring) {
      if(x == key || x == val){
          cout<< "can't wire " << x << " twice\n";
          return false;
      } 
      if(y == key || y == val){
          cout<< "can't wire " << y << " twice\n";
          return false;
      } 
    
    }if (!inAlphabet(x) || !inAlphabet(y)){
        cout<< "Characters must be in the aphabet\n";
        return false;
    }
    return true;
}

  
int main(){
    ChooseLanguage();
    int wires = 0;
    map<string, vector<string>> rotors;   
    if (alphabet.size() == 29){
        wires = 12;
        rotors = SwedishRotors();
    cout << "\n\n=== Rotors Configuration ===\n\n";
        printRotors(rotors);

    }if (alphabet.size() == 26){
        wires = 10;
        rotors = EnglishRotors();
    cout << "\n\n=== Rotors Configuration ===\n\n";
        printRotors(rotors);
    }


    string r1, r2, r3;
    cout << "Choose 3 rotors (e.g. III I V): ";
    cin >> r1 >> r2 >> r3;

    if (!rotors.count(r1) || !rotors.count(r2) || !rotors.count(r3)){
        cout << "Invalid rotor choice\n";
        return 0;
        
    }if (r1 == r2 || r1 == r3 || r2 == r3){
        cout << "Can't use the same rotor twice\n"; 
        return 0;
    }    

    int ring1, ring2, ring3;
    cout << "Enter ring settings for each rotor (e.g. 6 1 15): ";
    cin >> ring1 >> ring2 >> ring3;    

    if (ring1 < 1 || ring1 > alphabet.size() || ring2 < 1 || ring2 > alphabet.size() || ring3 < 1 || ring3 > alphabet.size()) {
        cout << "Ring settings must be between 1 and " << alphabet.size() << "\n";
    }


    string start1, start2, start3;
    cout << "Enter starting positions for each rotor(e.g. M C K): ";
    cin >> start1 >> start2 >> start3;

    start1 = toUpper(start1);
    start2 = toUpper(start2);
    start3 = toUpper(start3);

if (!inAlphabet(start1) || !inAlphabet(start2) || !inAlphabet(start3)) {
    cout << "Starting positions must be letters in the alphabet\n";
}

    string x, y;
    cout << "\n\n=== PLUGBOARD WIRING ===\n\n";
    cout << "Enter letter pairs to wire together.\n";
      
    while (wiring.size() < wires) {
        cout << "write pairs (eg. A B): ";
        cin >> x >> y;
        x = toUpper(x);
        y = toUpper(y);
        if (!wiring.empty()) {
          for (const auto& [key, val] : wiring)
              cout << key << " <-> " << val << "\n";
          
        }if (controll(x,y)) {
            wiring[x] = y;
            cout << "Paired " << x << " <-> " << y << "\n";
        }
    }    

    ofstream output_file("plugboard_settings.txt");
    output_file << r1 << " " << r2 << " " << r3 << "\n";
    output_file << ring1 << " " << ring2 << " " << ring3 << "\n";
    output_file << start1 << " " << start2 << " " << start3 << "\n";
    for (const auto& [key, val] : wiring)
        output_file << key << "/" << val << " ";
    output_file << "\n";
    output_file.close();

    return 0;
}
  

