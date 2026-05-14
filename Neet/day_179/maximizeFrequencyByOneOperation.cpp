// Problem Statement: Maximize Frequency of k
// Context:
// Amazon launched a "Play to Win" game where users can earn free gift vouchers.
// You are given an array of integers values and an integer k. You may choose any contiguous subarray and add an integer x of your choice to all elements in that subarray. This operation can be done at most once.
// Maximize the number of indices with value k in the resulting array, and return that maximum frequency.

// Example:
// values = [2, 3, 2, 4, 3, 2], k = 2
// Choose subarray [4, 3] (indices 3–4), add x = -2:

// 4 + (-2) = 2
// 3 + (-2) = 1

// New array: [2, 3, 2, 2, 1, 2]
// Value 2 now appears 4 times
// Output: 4

// Function Description:
// int maximizeFrequency(vector<int>& values, int k)
// Parameters:

// int[] values: the array of integers
// int k: the target value

// Returns: int — the maximum frequency of k after at most one subarray addition.
// Note: Since the full constraints weren't visible in the image, keep in mind:

// x can be any integer (positive, negative, or zero)
// The operation is optional (you can choose not to apply it)
// Only one contiguous subarray can be modified

class Solution
{
    int maximizeFrequency(vector<int>& values, int k)
    {
        int n = values.size();

        int numOfK = 0;
        unordered_set<int> distinctSet;
        for (int val : values) {
            if (val == k) {
                numOfK++;
            } else {
                distinctSet.insert(val);
            }
        }

        int maxGain = 0;
        // per val per subarray
        for (int val : distinctSet) {
            int curr = 0;
            for (int i=0; i<n; i++) {
                if (values[i] == val) {
                    curr++;
                } else if (values[i] == k) {
                    curr--;
                }
                if (curr < 0) curr = 0;
                maxGain = max(maxGain, curr);
            }
        }
        return numOfK+maxGain;
    }
};