# Question 2 — Server Upgrade Scheduling
# Given two servers and the time taken to upgrade each server in seconds, denoted by t1 and t2 respectively, in one second, one server undergoes the upgrade process. The servers receive requests at certain time intervals and pause upgrades during those seconds. The servers receive requests at multiples of req1 and req2 respectively. Determine the minimum total time (in seconds) required to upgrade both servers.
# Notes:
# Only one server undergoes the upgrade process at any given second.
# There may be seconds during which no server is undergoing an upgrade.

# Example
# req1 = 2
# t1 = 3
# req2 = 3
# t2 = 1
# The 1st server takes 3 seconds to upgrade, and it receives requests on seconds that are multiples of 2. Similarly, the 2nd server upgrades in 1 second and receives requests on seconds that are multiples of 3.
# The 1st server upgrades in the 1st, 3rd, and 5th seconds, while the 2nd server upgrades in the 2nd second. Note that none of the numbers from {1, 3, 5} is divisible by req1 = 2. Similarly, {2} is not divisible by req2 = 3. Thus, the minimum time required is 5 seconds.

# Function Description
# Complete the function getMinUpgradationTime in the editor below.
# getMinUpgradationTime takes the following parameters:
# int req1: indicates that the first server receives requests at multiples of req1
# int t1: the total time in seconds to upgrade the first server
# int req2: indicates that the second server receives requests at multiples of req2
# int t2: the total time in seconds to upgrade the second server

# Returns
# long: the minimum total time (in seconds) required to upgrade both servers

# Constraints
# 2 ≤ req1, req2 ≤ 3 × 10⁴
# 1 ≤ t1, t2 ≤ 10⁹


from math import gcd

class Solution:
    def getMinUpgradationTime(self, req1, t1, req2, t2) -> int:
        # least common multiple for req1 and req2
        # which seconds both server cannot upgrade
        lcm = (req1 * req2) // gcd(req1, req2)

        lo = 1
        hi = 2 * (t1 + t2) * max(req1, req2)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if self.canFinish(mid, t1, t2, req1, req2, lcm):
                hi = mid
            else:
                lo = mid+1
        return lo

    def canFinish(self, T, t1, t2, req1, req2, lcm) -> bool:
        usable1 = T - T // req1
        usable2 = T - T // req2
        usable_total = T - T // lcm
        return usable1 >= t1 and usable2 >= t2 and usable_total >= t1 + t2