// An array responseTime of n software components is given, 
// where responseTimep[i] represents the time taken by the i-th
// component to complete its task.

// A subarray of components is called a pipeline.
// The response time of a pipeline is defined as:
// Pipeline Response Time = (Maximum Response Time in the Pipeline) * # of components in the pipeline

// Return the sum of these response times for all possible pipelines modulo (10^9 + 7).

// Example:
// n = 3
// responseTime = [2, 3, 4]
// The response times of all the pipelines are:
// [2]: 2 * 1 = 2
// [3]: 3 * 1 = 3
// [4]: 4 * 1 = 4
// [2, 3]: 3 * 2 = 6
// [3, 4]: 4 * 2 = 8
// [2, 3, 4] = 4 * 3 = 12

// The sum of response times = 2 + 3 + 4 + 6 + 8 + 12 = 35,
// return 35 modulo (10^9 + 7).

// Function Description:
// Complete the function getResponseTimeSum with the following parameters:
// int responseTime[n]: the response time of each component

// Return:
// int: the sum of response times of all subgroups of n components modulo (10^9 + 7).
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int getResponseTimeSum(vector<int>& responseTimes) {
        const long long MOD = 1e9 + 7;
        int n = responseTimes.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // left[i] = how many steps we can go left where responseTimes[i] is max
        for (int i = 0; i < n; i++) {
            while (!st.empty() && responseTimes[st.top()] <= responseTimes[i]) {
                st.pop();
            }
            left[i] = st.empty() ? i : i - st.top() - 1;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // right[i] = how many steps we can go right where responseTimes[i] is max
        // use strict < to avoid double counting equal elements
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && responseTimes[st.top()] < responseTimes[i]) st.pop();
            right[i] = st.empty() ? n - i - 1 : st.top() - i - 1;
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long L = left[i], R = right[i];
            long long sumLen = (L + 1) * (R + 1) % MOD
                             + R * (R + 1) / 2 % MOD * (L + 1) % MOD
                             + L * (L + 1) / 2 % MOD * (R + 1) % MOD;
            res = (res + responseTimes[i] % MOD * (sumLen % MOD)) % MOD;
        }
        return res;
    }
};
