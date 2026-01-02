#include <vector>
using namespace std;

/*
    Problem: Search in Rotated Sorted Array

    Intuition:
    - At every step, one half of the array is sorted
    - Identify the sorted half
    - Check if target lies in that half
    - Narrow the search space accordingly
*/

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        int mid = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (arr[start] <= arr[mid]) {
                if (arr[start] <= target && target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (arr[mid] < target && target <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
