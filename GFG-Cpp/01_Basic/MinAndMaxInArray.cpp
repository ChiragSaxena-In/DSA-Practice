#include <vector>
using namespace std;

// Problem: Find Minimum and Maximum element in an array
// Approach: Linear Traversal
// Idea:
// - Assume first element as both minimum and maximum
// - Traverse the array and update min/max accordingly

class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {

        // Initializing min and max with first element
        int mn = arr[0];
        int mx = arr[0];

        // Traversing array from index 1
        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] > mx) {
                mx = arr[i];
            }

            if (arr[i] < mn) {
                mn = arr[i];
            }
        }

        // Returning {minimum, maximum}
        return {mn, mx};
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)

Why this works:
- Every element is compared once
- No extra data structures used
*/
