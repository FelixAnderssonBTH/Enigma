#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "language.h"

using namespace std;

class plugboard{

  private:
      
      map<string, string> wiring;

  public:
      
      
      bool controll(string x, string y, vector<string>& alphabet){
        
        if(x == y){
          cout<< "Cant pair with same letter\n";
          return false;
        
        }if (wiring.count(x)){
          cout<< "cant wire" << x << "twice\n";
          return false;
        
        }if (wiring.count(y)){
          cout<< "cant wire" << y << "twice\n";
          return false;
        }
        return true;
      }


      

}
