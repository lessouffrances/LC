#include <iostream>
#include <sched.h>
#include <vector>
#include <cstdio>
#include <numeric> 
#include <iterator>
#include <initializer_list>
using namespace std;

class Solution {
    public:

    void printVec(vector<int>& A)
    {
        for (int i=0; i<A.size(); i++) {
            if (i == A.size()-1) {
                printf("%d\n", A[i]);
            } else {
                printf("%d ", A[i]);
            }
        }
    }

    int subarraySum(vector<int>& nums, int k)
    {
        if (nums.empty()) return -1;
        int n = nums.size();
        int res = 0;
        
        // initialize an array to contain prefixSum
        vector<int> prefixSum(n+1);
        prefixSum[0] = 0;
        
        for (int end=1; end<n+1; end++) {
            prefixSum[end] = prefixSum[end-1] + nums[end-1];
        }
        printVec(prefixSum);
        
        for (int start=0; start<n+1; start++) {
            for (int end=start+1; end<n+1; end++) {
                printf("startIdx is %d\n", start);
                printf("endIdx is %d\n", end);
                int sum = prefixSum[end] - prefixSum[start];
                printf("The currSum is %d\n", sum);
                if (sum == k) res++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> numbers = {1, 2, 3};
    int k = 3;
    int actualRes = solution.subarraySum(numbers, k);
    if (actualRes == 2) {
        printf("pass!");
    }
}