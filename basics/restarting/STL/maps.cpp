#include<iostream>
#include<map>
using namespace std;

int main(){

    map<string, int> marks;

    marks["Gaurav"] = 95;
    marks["Pranjal"] = 88;
    marks["Amit"] = 87;
    marks["Riya"] = 93;
    marks["Ankit"] = 89;

    for(auto it = marks.begin(); it != marks.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }




    auto it = marks.find("Riya");
    if(it != marks.end()) {
        cout << "\nRiya is at: " << it->second << endl;
    } else {
        cout << "Riya not found." << endl;
    }

    marks.erase("Amit");
    

    cout<<"\nEntries After Erasing"<<endl;
    for(auto it = marks.begin(); it != marks.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }


    return 0;
}