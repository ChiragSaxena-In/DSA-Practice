#include <bits/stdc++.h>
using namespace std;

/*
    Book Allocation Problem (Binary Search on Answer)

    Problem Statement:
    - Given an array arr[] where arr[i] represents pages in the i-th book
    - Given k students
    - Each student must be allocated contiguous books
    - Each book must be allocated to exactly one student
    - Objective: Minimize the maximum number of pages assigned to any student

    Key Observations:
    - Order of books cannot be changed
    - At least one student has to read the largest book
    - At most, one student may read all books
*/

/*
    Intuition:
    - Instead of directly assigning books, we binary search the answer
    - Assume a value X as the maximum pages a student can read
    - Check if books can be allocated to k students without exceeding X
    - If possible, try smaller values (optimize)
    - If not possible, increase X

    This monotonic behavior makes binary search applicable
*/

/*
    Search Space:
    - Minimum possible answer = max(arr[i])
    - Maximum possible answer = sum(arr[i])
*/

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {

        // If students are more than books, allocation is impossible
        if (k > arr.size()) return -1;

        int start = arr[0];
        int end = 0;

        // Calculate search boundaries
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > start) {
                start = arr[i];     // max element
            }
            end += arr[i];          // sum of all pages
        }

        int res = -1;

        // Binary Search on answer
        while (start <= end) {

            int mid = start + (end - start) / 2;

            int count = 1;  // number of students
            int page = 0;   // pages assigned to current student

            // Check if allocation is possible with max pages = mid
            for (int i = 0; i < arr.size(); i++) {
                page += arr[i];

                if (page > mid) {
                    count++;
                    page = arr[i];
                }
            }

            // If allocation is possible, try minimizing maximum pages
            if (count <= k) {
                res = mid;
                end = mid - 1;
            }
            // Otherwise, increase allowed pages
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
      where N = number of books
            S = sum of pages

    Space Complexity:
    - O(1) extra space
*/

/*
    Category:
    - Binary Search on Answer
    - Greedy Allocation

    Similar Problems:
    - Painter's Partition Problem
    - Split Array Largest Sum
    - Capacity to Ship Packages Within D Days
*/
