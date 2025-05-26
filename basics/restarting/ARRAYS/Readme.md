🔹 STL Array
An STL array is a container that encapsulates fixed size arrays. It gives extra features like bounds checking, .at(), and easy traversal.

#include<array>
using namespace std;

array<int, 5> arr = {1, 2, 3, 4, 5};


✨ Key Functions:

arr.size() → returns size

arr.front() / arr.back() → first & last element

arr.at(i) → element at index i (safe version)


🔹 Vectors
A vector is like a dynamic array. It grows and shrinks as needed.

cpp
Copy
Edit
#include<vector>
using namespace std;

vector<int> v;
v.push_back(10);
v.push_back(20);
✨ Key Functions:

v.push_back(val) → add value

v.pop_back() → remove last element

v.size() → get size

v.clear() → remove all elements

v[i] or v.at(i) → access element

v.begin() / v.end() → iterators