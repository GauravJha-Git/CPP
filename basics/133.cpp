#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    bool visited[n]; // to track counted elements

    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
        visited[i] = false; // initialize
    }

    cout<<"Duplicate elements are :";

    for(int i = 0; i < n; i++) {
        if(visited[i]==true) continue;

        bool duplicate=false;

        for(int j= i+1; j < n; j++) {
            if (arr[i]==arr[j])
            {
                visited[j]=true;
                duplicate=true;
                
            }
            
        }

        if(duplicate){
            cout << arr[i] << " ";
        }
    }


    return 0;
}