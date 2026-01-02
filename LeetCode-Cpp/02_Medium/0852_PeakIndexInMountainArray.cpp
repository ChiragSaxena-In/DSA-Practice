#include <vector>
using namespace std;

/*
    Problem: Peak Index in a Mountain Array
*/

/*------------------------------------------------------------
    Solution 1: Binary Search on Mountain Property
------------------------------------------------------------

    Intuition:
    - A mountain array increases, reaches a peak, then decreases
    - At the peak:
          arr[mid] > arr[mid - 1] AND arr[mid] > arr[mid + 1]
    - If arr[mid] < arr[mid + 1], we are on the increasing slope
      → move right
    - Else we are on the decreasing slope
      → move left
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        int mid = 0;

        while (start <= end) {

            mid = start + ((end - start) / 2);

            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;
            } 
            else if (arr[mid] < arr[mid + 1] || mid == 0) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }

        return -1; 
    }
};
