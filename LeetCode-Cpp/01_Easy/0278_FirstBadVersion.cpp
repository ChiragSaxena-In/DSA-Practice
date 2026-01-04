#include <iostream>
using namespace std;

/*
    LeetCode 278 — First Bad Version

    Problem Idea:
    - Versions are numbered from 1 to n.
    - Once a version becomes bad, all versions after it are also bad.
      Pattern:
          F F F F T T T T

    - You are given a pre-defined API:
          bool isBadVersion(int version);

    Goal:
    - Find the FIRST bad version.

    Key Observation:
    - The versions follow a monotonic pattern (false → true),
      which makes this a classic Binary Search on Answer problem.

    Approach (Lower Bound of True):
    - Perform binary search on the range [1, n]
    - If mid is bad:
        - Store it as a potential answer
        - Continue searching in the left half
    - If mid is not bad:
        - Search in the right half

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version); // Assume this API is defined elsewhere

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int mid = 1;
        int ver = 1;   // Stores the first bad version found so far

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (isBadVersion(mid)) {
                ver = mid;          // Potential answer found
                end = mid - 1;      // Search for an earlier bad version
            } 
            else {
                start = mid + 1;    // Move to the right half
            }
        }

        return ver;
    }
};
