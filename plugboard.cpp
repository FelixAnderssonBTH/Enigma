#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>


#include "language.h"

using namespace std;

map<string, string> wiring; 

bool inAlphabet(const string& character) {
    return find(alphabet.begin(), alphabet.end(), character) != alphabet.end();
}

bool controll(string& x, string& y){
    
    if(x == y){
      cout<< "Cant pair with same letter\n";
      return false;
    
    }if (wiring.count(x)){
      cout<< "can't wire " << x << " twice\n";
      return false;
    
    }if (wiring.count(y)){
      cout<< "can't wire " << y << " twice\n";
      return false;
    }
    if (!inAlphabet(x) || !inAlphabet(y)){
      cout<< "Characters must be in the aphabet\n";
      return false;
    }
    return true;
  }

  
int main(){
    ChooseLanguage();
    int wires = 0;
    if (alphabet.size() == 29) wires = 12;
    if (alphabet.size() == 26) wires = 10;

    string x, y;
    cout << "=== PLUGBOARD WIRING ===\n";
    cout << "Enter letter pairs to wire together.\n";
    cout << "Type 'done' when finished.\n\n";
    
    while (wiring.size() < wires) {
        cout << "write pairs (eg. A B): ";
        cin >> x >> y;
        
        if (x.size() != 1) {
          cout << "you need to seperate the pairs with blankspace, and can only give one character at a time";
          continue;
        }
        if (y.size() != 1) {
          cout << "you need to seperate the pairs with blankspace, and can only give one character at a time";
          continue;
        }

        x[0] = toupper(x[0]);
        y[0] = toupper(y[0]);
        if (!wiring.empty()) {
          for (const auto& [key, val] : wiring)
              if (key < val)
                  cout << key << " <-> " << val << "\n";
          
          }if (controll(x,y)) {
            wiring[x] = y;
            wiring[y] = x;
            cout << "Paired " << x << " <-> " << y << "\n\n";
          }
    }

    return 0;
}
  

