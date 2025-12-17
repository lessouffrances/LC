class Solution:
    def maximumUnits(self, boxTypes, truckSize) -> int:
        # reverse sort the boxTypes on units
        boxTypes.sort(key=lambda x:x[1], reverse=True)
        print(boxTypes)
        res = 0

        for num, units in boxTypes:
            while num > 0 and truckSize > 0:
                num -= 1
                truckSize -= 1
                res += units
        print(res)
        return res

def main():
    solution = Solution()
    boxTypes = [[1,3],[2,2],[3,1]]
    truckSize = 4 #8

    # boxTypes = [[5,10],[2,5],[4,7],[3,9]]
    # truckSize = 10 #91

    solution.maximumUnits(boxTypes, truckSize)
main()
