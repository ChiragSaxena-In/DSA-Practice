#include <vector>
using namespace std;

/*
    Problem: Find Minimum in Rotated Sorted Array
*/

/*------------------------------------------------------------
    Solution 1: Binary Search on Rotation
------------------------------------------------------------

    Intuition:
    - In a rotated sorted array, one half is always sorted
    - Compare arr[mid] with arr[0]:
        - If arr[mid] >= arr[0], minimum lies to the right
        - Else arr[mid] can be the minimum, move left
    - Keep updating result when a smaller element is found
*/

class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        int mid = 0;

        int res = arr[0];

        while (start <= end) {

            mid = start + ((end - start) / 2);

            if (arr[mid] >= arr[0]) {
                start = mid + 1;
            } else {
                res = arr[mid];
                end = mid - 1;
            }
        }

        return res;
    }
};
