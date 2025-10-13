class Solution:
    def maximumUnits(self, boxTypes, truckSize) -> int:
        boxTypes.sort(key=lambda x:x[1], reverse=True)
        print(boxTypes)

        currValue = 0
        for [weight, price] in boxTypes:
            if weight > truckSize:
                currValue += truckSize * price
                truckSize -= truckSize
            else:
                currValue += weight * price
                truckSize -= weight
        return currValue
            


        # boxTypes.sort(key=lambda x:x[1], reverse=True)
        # print(boxTypes)

        # prices, weights = [], []

        # for info in boxTypes:
        #     for i in range(info[0]):
        #         prices.append(info[1])
        #         weights.append(1)
        # print(prices)
        # print(weights)
        
        # currValue = 0
        # for i, weight in enumerate(weights):
        #     if weight > truckSize:
        #         return currValue
            
        #     currValue += prices[i]
        #     truckSize -= 1

        # return currValue
        
def main():
    solution = Solution()
    boxTypes = [[1,3],[2,2],[3,1]]
    truckSize = 4 # 8
    print(solution.maximumUnits(boxTypes, truckSize))
main()