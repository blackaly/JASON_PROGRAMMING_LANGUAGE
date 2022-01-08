#include <iostream>
#include "helper.h"
using namespace std;

int main(int argc, char* argv[]){

    string input_to_user = " ";
    while(input_to_user != "q"){
        cout << "\n>> "; 
        getline(cin, input_to_user);
        cout << '\n';
        if(input_to_user != "q")
            scan(input_to_user);
        if(input_to_user == "clear")
            system("clear");
    }
    return 0;
}
