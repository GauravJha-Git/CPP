/*
🧾 QUESTION: Ways to Reach the n'th Stair

Difficulty: Medium  
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Your task is to count the number of ways the person can reach the top (order matters).

✨ Examples:

Input: n = 1
Output: 1
Explanation: Only one way – {1}

Input: n = 2
Output: 2
Explanation: Two ways – {1,1}, {2}

Input: n = 4
Output: 5
Explanation: 
Ways: {1,1,1,1}, {1,1,2}, {1,2,1}, {2,1,1}, {2,2}

🧠 APPROACH:

This is a Dynamic Programming problem and very similar to the Fibonacci series.
To reach stair 'n':
- You could come from stair 'n-1' with a 1-step.
- Or come from stair 'n-2' with a 2-step.

So the recurrence:
    ways(n) = ways(n-1) + ways(n-2)

🧱 BASE CASES:
- ways(1) = 1
- ways(2) = 2

We use a bottom-up DP approach with constant space.
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int countWays(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev2 = 1; // ways to reach stair 1
        int prev1 = 2; // ways to reach stair 2
        int curr;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2; // DP recurrence
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

// 🔍 Main Function to Run the Code
int main() {
    Solution obj;
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int result = obj.countWays(n);
    cout << "Number of ways to reach the " << n << "th stair: " << result << endl;

    return 0;
}

/*
🔎 CODE EXPLANATION:

1. We handle base cases directly: return 1 for n = 1 and return 2 for n = 2.
2. We initialize two variables `prev1` and `prev2` to represent:
   - ways to reach (n-1)th and (n-2)th stair.
3. For each step from 3 to n:
   - Use the formula: curr = prev1 + prev2
   - Update prev2 and prev1 for the next iteration.
4. Return the result stored in `curr`.

🧪 SAMPLE INPUT/OUTPUT:

Input:
Enter number of stairs: 5

Output:
Number of ways to reach the 5th stair: 8

(ways: [1,1,1,1,1], [1,1,1,2], [1,1,2,1], [1,2,1,1], [2,1,1,1], [2,2,1], [2,1,2], [1,2,2])
*/
