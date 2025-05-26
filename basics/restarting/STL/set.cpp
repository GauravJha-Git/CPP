#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(5); // Duplicate ignored

    for(auto val : s) {
        cout << val << " ";
    }
    return 0;
}
