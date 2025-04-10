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

    cout << "\nFrequencies:\n";
    for(int i = 0; i < n; i++) {
        if(visited[i] == true)
            continue;

        int count = 1;

        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = true;
            }
        }

        cout << arr[i] << " → " << count << " time(s)" << endl;
    }

    return 0;
}
