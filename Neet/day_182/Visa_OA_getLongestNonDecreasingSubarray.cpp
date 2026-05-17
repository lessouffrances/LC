// T3 — Longest Non-Decreasing Subarray from Two Arrays
// Problem: Given two equal-length arrays A and B, 
// find the longest contiguous subarray such that for every position i in the subarray, 
// we can pick either A[i] or B[i], and the chosen values form a non-decreasing sequence.
// Approach: DP. Define:

// dpa[i] = longest valid subarray ending at index i where we pick A[i]
// dpb[i] = longest valid subarray ending at index i where we pick B[i]

// For each i, if the current choice is >= the previous position's choice, 
// extend that state by 1, otherwise reset to 1.

#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
    public:
    int longestNonDecreasing(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) return 0;
        int n = A.size();
        int dpa = 1, dpb = 1, res = 1;

        for (int i = 1; i < n; i++) {
            int new_dpa = 1, new_dpb = 1;
            if (A[i] >= A[i-1]) new_dpa = max(new_dpa, dpa + 1);
            if (A[i] >= B[i-1]) new_dpa = max(new_dpa, dpb + 1);
            if (B[i] >= A[i-1]) new_dpb = max(new_dpb, dpa + 1);
            if (B[i] >= B[i-1]) new_dpb = max(new_dpb, dpb + 1);
            dpa = new_dpa;
            dpb = new_dpb;
            res = max(res, max(dpa, dpb));
        }
        return res;
    }
};