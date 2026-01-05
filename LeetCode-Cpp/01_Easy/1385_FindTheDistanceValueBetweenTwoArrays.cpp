#include <vector>
#include <cmath>
using std::vector;

/*
    Find the Distance Value Between Two Arrays - Brute Force (Solution 1)

    Problem:
    - Given two integer arrays arr1 and arr2, and an integer d
    - Count how many elements in arr1 have no element in arr2
      such that |arr1[i] - arr2[j]| <= d
    - Return this count as the distance value

    Idea:
    - For each element in arr1:
        - Check against every element in arr2
        - If no element violates the distance condition, count it
    - Brute force approach: O(n*m), where n = arr1.size(), m = arr2.size()

    Time Complexity:
    - O(n * m)

    Space Complexity:
    - O(1)
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        for (int i = 0; i < arr1.size(); i++) {
            bool happen = 0;   // reset for each arr1 element

            for (int j = 0; j < arr2.size(); j++) {
                if (std::abs(arr1[i] - arr2[j]) <= d) {
                    happen = 1;
                    break;
                }
            }

            if (!happen) ans++;
        }

        return ans;
    }
};
