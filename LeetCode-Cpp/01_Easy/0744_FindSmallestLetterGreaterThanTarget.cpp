#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 744 — Find Smallest Letter Greater Than Target

    Problem Idea:
    - Given a sorted array of characters 'letters' and a character 'target'
    - Return the **smallest letter in the array that is greater than target**
    - Letters wrap around, so if target >= all letters, return letters[0]

    Key Observation:
    - The array is sorted → we can use Binary Search to find the **first letter > target**
    - This is a **lower bound style search** on characters

    Approach:
    1. Initialize search space: start = 0, end = letters.size() - 1
    2. Initialize result: res = letters[0] (wrap-around default)
    3. While start <= end:
        - mid = start + (end - start)/2
        - If letters[mid] > target:
            - Potential answer found → store in res
            - Move left: end = mid - 1
        - Else:
            - Move right: start = mid + 1
    4. Return res

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;
        int mid = 0;
        char res = letters[0];  // Default wrap-around answer

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (letters[mid] > target) { //Upper Bound
                res = letters[mid];   // Potential answer found
                end = mid - 1;        // Search left half for smaller letter > target
            } 
            else {
                start = mid + 1;      // Search right half
            }
        }

        return res;
    }
};
