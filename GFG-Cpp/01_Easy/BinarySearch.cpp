#include <iostream>
#include <vector>
using namespace std;

/*
    First Occurrence in a Sorted Array (Binary Search)

    Problem Idea:
    - Given a sorted array and a target value k
    - Return the index of the FIRST occurrence of k
    - If k is not present, return -1

    Example:
    arr = [1, 2, 2, 2, 3, 4], k = 2
    Output = 1

    Key Observation:
    - Since the array is sorted, all occurrences of k (if any)
      will be contiguous.
    - This becomes a Binary Search problem where we look for
      the LEFTMOST (first) occurrence of k.

    Approach:
    - Perform binary search
    - When k is found:
        - Store the index as a potential answer
        - Continue searching in the left half to find an earlier occurrence

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        int mid = 0;
        int res = -1;   // Stores first occurrence index

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (arr[mid] == k) {
                res = mid;          // Possible answer found
                end = mid - 1;      // Move left to find first occurrence
            }
            else if (arr[mid] < k) {
                start = mid + 1;    // Search right half
            }
            else {
                end = mid - 1;      // Search left half
            }
        }

        return res;
    }
};
