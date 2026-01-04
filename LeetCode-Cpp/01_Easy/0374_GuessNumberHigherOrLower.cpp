#include <iostream>
using namespace std;

/*
    LeetCode 374 — Guess Number Higher or Lower

    Problem Idea:
    - A number is picked by the system between 1 and n (inclusive).
    - You do NOT know the picked number.
    - You are given a pre-defined API:
          int guess(int num);

    guess(num) returns:
    -1  → num is higher than the picked number
     1  → num is lower than the picked number
     0  → num is equal to the picked number

    Key Observation:
    - Since the response tells us whether our guess is too high or too low,
      this is a perfect application of Binary Search.

    Approach:
    - Apply binary search on the range [0, n]
    - Call guess(mid) at every step
    - Adjust search space based on API response

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *                0 if num is correct
 * int guess(int num);
 */
int guess(int num); // Assume this API is defined elsewhere

class Solution {
public:
    int guessNumber(int n) {
        int start = 0;
        int end = n;
        int mid = 0;
        int res = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;

            res = guess(mid);

            if (res == 0) {
                return mid;            // Correct guess
            }
            else if (res == -1) {
                end = mid - 1;         // Guess is too high
            }
            else {
                start = mid + 1;       // Guess is too low
            }
        }

        // Problem guarantees a valid answer exists
        return mid;
    }
};
