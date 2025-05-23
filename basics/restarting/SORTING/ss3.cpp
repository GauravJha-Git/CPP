#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, bool ascending) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int selected = i;

        for (int j = i + 1; j < n; ++j) {
            if (ascending) {
                if (arr[j] < arr[selected])
                    selected = j;
            } else {
                if (arr[j] > arr[selected])
                    selected = j;
            }
        }

        swap(arr[i], arr[selected]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    char order;
    cout << "Sort in ascending (a) or descending (d)? ";
    cin >> order;

    bool ascending;

    if (order == 'a' || order == 'A') {
        ascending = true;
    } else if (order == 'd' || order == 'D') {
        ascending = false;
    } else {
        cout << "Invalid input. Defaulting to ascending sort.\n";
        ascending = true;
    }

    selectionSort(arr, ascending);

    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
