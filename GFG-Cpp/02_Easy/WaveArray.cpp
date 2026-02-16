#include <vector>
using namespace std;

/*
=========================================================
Problem: Sort in Wave Form
Platform: GFG
Concept: Array Manipulation
=========================================================

Definition:
Given a sorted array, rearrange it in wave form such that:

arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] ...

IMPORTANT:
This solution assumes that the array is already sorted
in non-decreasing order.

---------------------------------------------------------

Example:

Input:
1 2 3 4 5

Output:
2 1 4 3 5

---------------------------------------------------------

IDEA:
Since the array is already sorted:

arr[0] <= arr[1] <= arr[2] <= arr[3] ...

Swapping every adjacent pair automatically creates:

arr[0] >= arr[1] <= arr[2] >= arr[3] ...

So no additional sorting is required.

---------------------------------------------------------

APPROACH:

1. Traverse array with step of 2:
   i = 0, 2, 4, ...

2. Swap arr[i] and arr[i+1]

3. Stop before last element if size is odd.

---------------------------------------------------------

Time Complexity:
O(N)

Space Complexity:
O(1)

=========================================================
*/

class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        
        int N = arr.size();
        
        // NOTE: Assumes the array is already sorted
        // in non-decreasing order.
        
        for (int i = 0; i < N - 1; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
    }
};
