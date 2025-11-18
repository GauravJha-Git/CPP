#include <iostream>
#include <string>
using namespace std;

bool divBy11(string &s) {
    
    // Convert string to int
    int n = stoi(s); 
    return n % 11 == 0;
}

int main() {
    string s = "76945";

    if (divBy11(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}