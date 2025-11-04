class Solution:
    def canCompleteCircuit(self, gas, cost) -> int:
        if sum(gas) < sum(cost):
            return -1
        # convert to the real problem
        for i in range(len(gas)):
            real_gas, real_cost = gas[ i : ]+gas[ : i+1 ], cost[ i : ]+cost[ : i+1 ]
            print(f"Real Gas is: {real_gas}", end="\n")
            print(f"Real Cost is: {real_cost}", end="\n")
            
            # assume this starting index is True
            qualified = True
            curr_tank = 0
            for j in range(len(real_gas)):
                curr_tank += (real_gas[j]-real_cost[j])
                print(f"The curr tank is: {curr_tank}", end="\n\n")
                # if at any point in time the tank is negative, break and this starting index is False
                if curr_tank < 0:
                    qualified = False
                    curr_tank = 0
                    break
            if qualified:
                return i
        return -1

def main():
    solution = Solution()
    gas = [1,2,3,4,5]
    cost = [3,4,5,1,2] #3

    # gas = [2,3,4]
    # cost = [3,4,3] #-1

    print(solution.canCompleteCircuit(gas, cost))

main()