class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int):
        lst = []
        for i in range(len(candies)):
            candies[i] = candies[i] + extraCandies
            lst.append(max(candies) == candies[i])
            candies[i] = candies[i] - extraCandies
        print(lst)



def main():
    self = Solution()
    
    # candies = [2,3,5,1,3]
    # candies = [4,2,1,1,2]
    candies = [12,1,12]
    extraCandies = 10

    Solution.kidsWithCandies(self, candies, extraCandies)
    
main()