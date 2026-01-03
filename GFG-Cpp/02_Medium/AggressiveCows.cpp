#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {

        /*
            Problem Type:
            - Binary Search on Answer

            Goal:
            - Place k cows in stalls such that the minimum distance
              between any two cows is maximized.
        */

        int n = arr.size();

        // Sort stall positions
        sort(arr.begin(), arr.end());

        // Minimum possible distance
        int start = 1;

        // Maximum possible distance (first stall to last stall)
        int end = arr[n - 1] - arr[0];

        int mid = 0;
        int res = 0;

        // Binary Search on minimum distance
        while (start <= end) {

            mid = start + (end - start) / 2;

            /*
                Check if we can place k cows
                with at least 'mid' distance between them
            */
            int cow = 1;                 // first cow placed at first stall
            int lastPosition = arr[0];

            for (int i = 1; i < n; i++) {
                if (arr[i] - lastPosition >= mid) {
                    cow++;
                    lastPosition = arr[i];
                }
            }

            // If not possible, reduce the distance
            if (cow < k) {
                end = mid - 1;
            }
            // If possible, try to increase the distance
            else {
                res = mid;
                start = mid + 1;
            }
        }

        return res;
    }
};
