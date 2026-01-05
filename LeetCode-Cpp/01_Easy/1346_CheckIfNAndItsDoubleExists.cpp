#include <vector>
#include <algorithm>
using std::vector;

/*
    Check If N and Its Double Exist

    Problem:
    - Given an integer array arr, check if there exist two indices i and j such that:
        - i != j
        - arr[i] == 2 * arr[j]
    - Return true if such a pair exists, else false

    Idea:
    - Sort the array (optional, helps if you want ordered traversal)
    - Use two nested loops to check every pair (i, j)
    - Skip when i == j
    - If arr[i] == 2 * arr[j], return true

    Time Complexity:
    - O(n^2)

    Space Complexity:
    - O(1)
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        bool isPossible = false;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i == j) continue;

                if (arr[i] == 2 * arr[j]) {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible) break;  // early exit if found
        }

        return isPossible;
    }
};
