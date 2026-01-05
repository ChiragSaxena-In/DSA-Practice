#include <vector>
using std::vector;

/*
    Array Linear Search

    Problem:
    - Given an array and an element x
    - Find the index of x in the array
    - If not found, return -1

    Idea:
    - Traverse the array from left to right
    - Compare each element with x
    - Return index immediately when match is found

    Time Complexity:
    - O(n)

    Space Complexity:
    - O(1)
*/

class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
};
