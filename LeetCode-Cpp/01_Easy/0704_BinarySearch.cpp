#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;

        while (start <= end) {

            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return -1;
    }
};

/*
Intuition:
Use binary search on the sorted array.
Check the middle element each time and discard half of the search space.
If the target exists, return its index, otherwise return -1.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
