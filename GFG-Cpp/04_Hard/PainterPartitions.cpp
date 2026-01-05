#include <bits/stdc++.h>
using namespace std;

/*
    Painter's Partition Problem

    Problem Statement:
    - Given an array arr[] where arr[i] represents the time to paint the i-th board
    - Given k painters
    - Each painter paints contiguous boards only
    - Each board must be painted by exactly one painter
    - Objective: Minimize the maximum time taken by any painter
*/

/*
    Intuition:
    - Instead of assigning boards directly, we binary search on the answer
    - Assume a value X as the maximum time a painter can take
    - Check if all boards can be painted using k painters such that
      no painter exceeds time X
    - If possible, try smaller values
    - If not possible, increase X

    This works because feasibility is monotonic
*/

/*
    Search Space:
    - Minimum possible time = max(arr[i])
      (a painter must paint at least the largest board)
    - Maximum possible time = sum(arr[i])
      (one painter paints all boards)
*/

class Solution {
  public:
    int minTime(vector<int> &arr, int k) {

        int start = arr[0];
        int end = 0;

        // Calculate search boundaries
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > start) {
                start = arr[i];
            }
            end += arr[i];
        }

        // If only one painter is available
        if (k == 1) return end;

        int res = 0;

        // Binary Search on answer
        while (start <= end) {

            int mid = start + (end - start) / 2;

            int painter = 1;     // number of painters required
            int timereq = 0;     // time assigned to current painter

            // Check feasibility for mid
            for (int i = 0; i < arr.size(); i++) {
                timereq += arr[i];

                if (timereq > mid) {
                    painter++;
                    timereq = arr[i];
                }
            }

            // If allocation is possible, try minimizing maximum time
            if (painter <= k) {
                res = mid;
                end = mid - 1;
            }
            // Otherwise, increase allowed time
            else {
                start = mid + 1;
            }
        }

        return res;
    }
};

/*
    Time Complexity:
    - O(N log S)
      where N = number of boards
            S = sum of board lengths

    Space Complexity:
    - O(1) extra space
*/

/*
    Category:
    - Binary Search on Answer
    - Greedy Feasibility Check

    Related Problems:
    - Book Allocation Problem
    - Split Array Largest Sum
    - Allocate Minimum Number of Pages
*/
