#include <iostream>
using namespace std;

/*
    LeetCode 367 — Valid Perfect Square

    Problem Idea:
    - Determine if a number 'num' is a perfect square without using sqrt()
    - Binary Search is used as an **existence check** with a monotonic predicate:
        mid*mid <= num

    Approach:
    1. Edge case: if num == 1, return true
    2. Search space: start = 1, end = num / 2
    3. While start <= end:
        - mid = start + (end - start)/2
        - If mid*mid == num → return true
        - If mid*mid < num → move right: start = mid + 1
        - Else → move left: end = mid - 1
    4. If no mid satisfies the condition → return false

    Time Complexity: O(log num)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;   // Edge case

        int start = 1;
        int end = num / 2;            // Maximum meaningful mid
        long long mid = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (mid * mid == num) { 
                return true;          // Found perfect square
            } 
            else if (mid * mid < num) {
                start = mid + 1;      // Move right
            } 
            else {
                end = mid - 1;        // Move left
            }
        }

        return false;                 // No perfect square found
    }
};
