#include <vector>
using namespace std;

/*
    Problem: Kth Missing Positive Number
    Given a sorted array of positive integers (nums),
    find the k-th missing positive number.
*/

/*------------------------------------------------------------
    Solution 1: Linear Scan / Simulation
------------------------------------------------------------

    Intuition:
    - Start checking numbers from 1 onwards
    - Compare current expected number (num) with nums[i]
    - If they match → number exists, move forward in array
    - If they don’t match → number is missing, increase count
    - Stop when count == k

    Time Complexity: O(n + k)
    Space Complexity: O(1)

    Pros:
    - Very intuitive
    - Easy to reason about
    - No math tricks

    Cons:
    - Slightly slower when k is large
*/

class SolutionLinear {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int res = 0;
        int num = 1;
        int count = 0;

        for (int i = 0; i < nums.size(); ) {
            if (nums[i] == num) {
                i++;
                num++;
            } else {
                res = num;
                num++;
                count++;
            }

            if (count == k) {
                return res;
            }
        }

        // If missing numbers continue after array ends
        while (count < k) {
            res = num;
            num++;
            count++;
        }

        return res;
    }
};

/*------------------------------------------------------------
    Solution 2: Binary Search (Optimized)
------------------------------------------------------------

    Key Observation:
    - At index i (0-based),
      missing numbers till nums[i] =
            nums[i] - (i + 1)

    Intuition:
    - Use binary search to find the first index
      where missing numbers >= k
    - Then compute the answer directly

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Pros:
    - Fast
    - Clean mathematical approach

    Cons:
    - Less intuitive than linear scan
*/

class SolutionBinary {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int missing = nums[mid] - (mid + 1);

            if (missing < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // start is the position where kth missing lies
        return start + k;
    }
};
