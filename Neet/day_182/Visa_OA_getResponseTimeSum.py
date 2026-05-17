# An array responseTime of n software components is given, 
# where responseTimep[i] represents the time taken by the i-th
# component to complete its task.

# A subarray of components is called a pipeline.
# The response time of a pipeline is defined as:
# Pipeline Response Time = (Maximum Response Time in the Pipeline) * # of components in the pipeline

# Return the sum of these response times for all possible pipelines modulo (10^9 + 7).

# Example:
# n = 3
# responseTime = [2, 3, 4]
# The response times of all the pipelines are:
# [2]: 2 * 1 = 2
# [3]: 3 * 1 = 3
# [4]: 4 * 1 = 4
# [2, 3]: 3 * 2 = 6
# [3, 4]: 4 * 2 = 8
# [2, 3, 4] = 4 * 3 = 12

# The sum of response times = 2 + 3 + 4 + 6 + 8 + 12 = 35,
# return 35 modulo (10^9 + 7).

# Function Description:
# Complete the function getResponseTimeSum with the following parameters:
# int responseTime[n]: the response time of each component

# Return:
# int: the sum of response times of all subgroups of n components modulo (10^9 + 7).


class Solution:
    def getResponseTimeSum(self, responseTimes) -> int:
        MOD = 10**9 + 7
        n = len(responseTimes)
        left = [0] * n
        right = [0] * n
        st = []

        # left[i] = how many steps we can go left where responseTimes[i] is max
        for i in range(n):
            while st and responseTimes[st[-1]] <= responseTimes[i]:
                st.pop()
            left[i] = i if not st else i - st[-1] - 1
            st.append(i)

        st.clear()

        # right[i] = how many steps we can go right where responseTimes[i] is max
        # use strict < to avoid double counting equal elements
        for i in range(n - 1, -1, -1):
            while st and responseTimes[st[-1]] < responseTimes[i]:
                st.pop()
            right[i] = n - i - 1 if not st else st[-1] - i - 1
            st.append(i)

        res = 0
        for i in range(n):
            L, R = left[i], right[i]
            sum_len = ((L + 1) * (R + 1)
                     + R * (R + 1) // 2 * (L + 1)
                     + L * (L + 1) // 2 * (R + 1)) % MOD
            res = (res + responseTimes[i] * sum_len) % MOD

        return res
