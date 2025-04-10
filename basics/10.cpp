#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    bool visited[n] = {false}; // to keep track of counted elements

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "\nFrequencies:\n";
    for(int i = 0; i < n; i++){
        if(visited[i] == true)
            continue;

        int count = 1;
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                visited[j] = true;
                count++;
            }
        }

        cout << arr[i] << " occurs " << count << " time \n";
        
        
    }

    return 0;
}
