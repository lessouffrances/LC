class Solution:
    def kidsWithCandies(self, candies, extraCandies: int):
        res = []
        for candy in candies:
            added = candy + extraCandies
            if added >= max(candies):
                res.append(True)
            else:
                res.append(False)
        return res
                


        


def main():
    self = Solution
    candies = [2,3,5,1,3]
    extraCandies = 3
    print(Solution.kidsWithCandies(self, candies, extraCandies))
main()