#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(1);
    ms.insert(1);
    ms.insert(3);
    ms.insert(2);

    for(auto val : ms) {
        cout << val << " ";
    }

    ms.erase(5);

    cout<<"\nAfter deletion: "<<endl;
    for(auto val : ms) {
        cout << val << " ";
    }

    return 0;
}
