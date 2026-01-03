// User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int n, int k) {

        /*
            Problem Type:
            - Binary Search on Answer
            - Similar to Book Allocation / Ship Capacity problems

            Goal:
            - Find the minimum capacity such that all items can be shipped
              within at most k days.
            - Order of items must be preserved.
        */

        // Minimum possible capacity = maximum element
        // Maximum possible capacity = sum of all elements
        int start = arr[0], end = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > start) {
                start = arr[i];
            }
            end += arr[i];
        }

        // If only one day is allowed, all items must be shipped together
        if (k == 1) return end;

        int mid = 0;
        int res = 0;

        // Binary Search on capacity
        while (start <= end) {

            mid = start + (end - start) / 2;

            /*
                Check if we can ship all items within k days
                using 'mid' as the capacity
            */
            int day = 1;
            int currentWeight = 0;

            for (int i = 0; i < n; i++) {
                currentWeight += arr[i];

                // If capacity exceeded, move to next day
                if (currentWeight > mid) {
                    day++;
                    currentWeight = arr[i];
                }
            }

            // If feasible, try minimizing the capacity
            if (day <= k) {
                res = mid;
                end = mid - 1;
            }
            // Otherwise, increase capacity
            else {
                start = mid + 1;
            }
        }

        return res;
    }
};
