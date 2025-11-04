class Solution:
    def canCompleteCircuit(self, gas, cost) -> int:
        if sum(cost) > sum(gas):
            return -1

        total, start = 0, 0
        for i in range(len(gas)):
            total += gas[i]-cost[i]
            if total < 0:
                start = i+1
                total = 0

        return start

        

def main():
    solution = Solution()
    gas = [1,2,3,4,5]
    cost = [3,4,5,1,2] #3

    # gas = [2,3,4]
    # cost = [3,4,3] #-1

    print(solution.canCompleteCircuit(gas, cost))

main()