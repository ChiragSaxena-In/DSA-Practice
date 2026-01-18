#include <vector>
using namespace std;


// ============================================================
// Problem: Running Sum of 1D Array
// Technique: Prefix Sum
// ============================================================

/*
    Idea:
    - Each element at index i should store the sum of all elements
      from index 0 to i.
    - Instead of recomputing the sum every time, reuse the previous sum.

    Intuition (Prefix Sum):
    - nums[i] already holds the value at index i
    - nums[i-1] holds the sum till previous index
    - So:
          nums[i] = nums[i] + nums[i-1]

    This builds the prefix sum array in-place.
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        // Start from index 1 because index 0 is already correct
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        return nums;
    }
};

/*
    Time Complexity:  O(n)
    Space Complexity: O(1)  (in-place modification)

    Notes:
    - This is a classic prefix sum pattern.
    - Very useful in range queries, cumulative frequency,
      and optimization problems.
*/
