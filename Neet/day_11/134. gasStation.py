class Solution:
    def canCompleteCircuit(self, gas, cost) -> int:
        if sum(gas) < sum(cost):
            return -1
        
        total = 0
        start = 0
        for i in range(len(gas)):
            total += (gas[i] - cost[i])

            if total < 0:
                total = 0
                start = i+1

        return start 


def main():
    self = Solution()
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    print(Solution.canCompleteCircuit(self, gas, cost))

main()