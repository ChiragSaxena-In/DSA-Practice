#include <vector>
using namespace std;

/*
------------------------------------------------------------
Problem: Two Sum II - Input Array Is Sorted
Approach: Two Pointer
Indexing: 1-based (as required by the problem)
------------------------------------------------------------
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &arr, int target) {

        // Pointers at both ends of the sorted array
        int start = 0;
        int end = arr.size() - 1;

        // Keep shrinking the search space
        while (start < end) {

            int currSum = arr[start] + arr[end];

            // Case 1: Pair found
            if (currSum == target) {
                // +1 because problem expects 1-based indexing
                return {start + 1, end + 1};
            }
            // Case 2: Sum too small → increase left pointer
            else if (currSum < target) {
                start++;
            }
            // Case 3: Sum too large → decrease right pointer
            else {
                end--;
            }
        }

        // No valid pair found
        return {-1, -1};
    }
};
