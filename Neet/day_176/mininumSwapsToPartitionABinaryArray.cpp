// Given a binary array of 0s and 1s, group all elements of the 
// same value together on either side of the array by swapping 
// adjacent elements. Return the minimum number of adjacent swaps 
// required to achieve such a partition.
// Note: The final array does not need to be fully sorted 
// — it is sufficient that all 0s are contiguous on one side or 
// ll 1s are contiguous on one side.

// Example 1:
// Input:  [1, 0, 1, 0, 0, 1]
// Output: 2
// Example 2:
// Input:  [1, 1, 1, 1, 0, 1, 0, 1]
// Output: 3

// Constraints:

// 1 <= arr.length <= 10^5
// arr[i] is either 0 or 1

class Solution
{
    public:
    int minSwaps(vector<int>& arr) {
        int swaps0 = 0, swaps1 = 0;
        int onesCount = 0, zerosCount = 0;
    
        for (int x : arr) {
            if (x == 1) {
                onesCount++;
                swaps1 += zerosCount;  // this 1 must pass all prior 0s
            } else {
                zerosCount++;
                swaps0 += onesCount;   // this 0 must pass all prior 1s
            }
        }
    
        return min(swaps0, swaps1);
    }
};