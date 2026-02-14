#include <vector>
using namespace std;

/*
=========================================================
Count Dominant Indices
=========================================================

Definition:
An index i is dominant if:
nums[i] > average of elements after index i.

Two Approaches:
1. Brute Force - O(n^2)
2. Optimized - O(n)

=========================================================
*/

class Solution {
public:

    /*
    -----------------------------------------------------
    Approach 1: Brute Force
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    -----------------------------------------------------
    */
    int dominantIndicesBrute(vector<int>& nums) {
        
        int n = nums.size();
        int dominantCount = 0;
        
        for (int i = 0; i < n - 1; i++) {
            
            long long sum = 0;
            int count = 0;
            
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                count++;
            }
            
            double average = (double)sum / count;
            
            if (nums[i] > average) {
                dominantCount++;
            }
        }
        
        return dominantCount;
    }

    /*
    -----------------------------------------------------
    Approach 2: Optimized
    Time Complexity: O(n)
    Space Complexity: O(1)
    -----------------------------------------------------
    */
    int dominantIndicesOptimized(vector<int>& nums) {
        
        int n = nums.size();
        int dominantCount = 0;
        
        long long totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }
        
        long long remainingSum = totalSum;
        
        for (int i = 0; i < n - 1; i++) {
            
            remainingSum -= nums[i];
            int remainingCount = n - i - 1;
            
            if ((long long)nums[i] * remainingCount > remainingSum) {
                dominantCount++;
            }
        }
        
        return dominantCount;
    }
};
