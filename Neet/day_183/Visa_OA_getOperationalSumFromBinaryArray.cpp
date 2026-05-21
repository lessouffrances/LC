// Question 2 — Binary Array AND Sum
// Given a binary array of 0s and 1s, repeatedly apply the following operation:

// Compute sum of the current array and add it to the result
// Replace array[i] = array[i] & array[i+1] for all valid i
// Repeat until one element remains

// Return the total result.
// Function Description:
// long computeResult(int[] arr)
// Returns: long — the total sum across all operations.

// Example:
// arr = [1, 0, 1, 1]
// Output: 6

// Constraints:
// 1 <= n <= 10^6
// arr[i] is 0 or 1

// TLE but correct solution
class Solution
{
    long computeResult(vector<int> arr)
    {
        vector<int> curr = arr;
        long res = 0;

        while (curr.size() > 0) {
            for (int num : curr) {
                res += num;
            }

            vector<int> next;
            for (int i=0; i<curr.size()-1; i++) {
                next.push_back(curr[i] & curr[i+1]);
            }
            curr = next;
        }
        return res;
    }
};

// Optimized Solution
// only 1 & 1 will remain.
class Solution
{
    long computeResult(vector<int> arr)
    {
        int n = arr.size();
        long res = 0;

        int consecutive = 0;
        for (int i=n-1; i>=0; i--) {
            if (arr[i] == 1) {
                consecutive++;
            } else {
                consecutive = 0;
            }
            res += consecutive;
        }
        return res;
    }
};


