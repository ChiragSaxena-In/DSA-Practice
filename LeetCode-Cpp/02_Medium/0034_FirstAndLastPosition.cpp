#include <vector>
using namespace std;

class Solution {
public:

    // -------- Solution 1: Linear Search --------
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int first = -1, second = -1;
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (!found) {
                    found = true;
                    first = i;
                }
                second = i;
            }
        }

        return {first, second};
    }

    // -------- Solution 2: Binary Search --------
    vector<int> searchRangeBinary(vector<int>& nums, int target) {

        int n = nums.size();
        int first = -1, second = -1;
        int start = 0, end = n - 1;
        int mid = 0;

        // Find first occurrence
        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        start = 0;
        end = n - 1;

        // Find last occurrence
        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                second = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return {first, second};
    }
};

/*
====================== Intuition ======================

Solution 1 (Linear Search):
Traverse the array once.
When the target is found for the first time, store its index as first.
Keep updating second for every further occurrence.
If the target does not exist, both remain -1.

Time Complexity: O(n)
Space Complexity: O(1)

------------------------------------------------------

Solution 2 (Binary Search):
Since the array is sorted, binary search can be applied.
Run binary search twice:
- First search moves left after finding target to get the first occurrence.
- Second search moves right after finding target to get the last occurrence.

Time Complexity: O(log n)
Space Complexity: O(1)

======================================================
*/
