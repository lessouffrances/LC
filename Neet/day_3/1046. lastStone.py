class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        stones = sorted(stones)
        # print(sorted_stones)

        while len(stones) > 1:
            first = stones.pop()
            # print(first)
            second = stones.pop()
            # print(second)
            if first > second:
                stones.append(first - second)
                stones = sorted(stones)
        
        if len(stones) == 0:
            stones.append(0)

        # print(sorted_stones)
        return stones[0]

            

def main():
    self = Solution()
    stones = [2, 7, 4, 1, 8, 1]
    print(Solution.lastStoneWeight(self, stones))



main()