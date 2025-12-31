#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int n = nums.size();
        int start = 0, end = n - 1;
        int mid = 0;
        int result = n;

        while (start <= end) {

            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                // Possible insertion position
                result = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return result;
    }
};

/*
Intuition:
Apply binary search on the sorted array.
If target is found, return its index.
Otherwise, keep track of the smallest index where nums[mid] > target, i.e Find Upper Bound.
That index becomes the insertion position.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
