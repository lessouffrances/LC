# Question 2 — Binary Array AND Sum
# Given a binary array of 0s and 1s, repeatedly apply the following operation:

# Compute sum of the current array and add it to the result
# Replace array[i] = array[i] & array[i+1] for all valid i
# Repeat until one element remains

# Return the total result.
# Function Description:
# long computeResult(int[] arr)
# Returns: long — the total sum across all operations.

# Example:
# arr = [1, 0, 1, 1]
# Output: 6

# Constraints:
# 1 <= n <= 10^6
# arr[i] is 0 or 1

# TLE but correct solution
class Solution