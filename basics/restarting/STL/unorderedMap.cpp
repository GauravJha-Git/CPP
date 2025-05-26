#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> score;
    score["Gaurav"] = 100;
    score["Rahul"] = 85;
    score["Priya"] = 90;

    for(auto pair : score) {
        cout << pair.first << " : " << pair.second << endl;
    }
    return 0;
}
