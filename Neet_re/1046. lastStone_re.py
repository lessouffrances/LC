class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        stones = sorted(stones)

        while len(stones) > 1:
            first = stones.pop()
            second = stones.pop()

            if first > second:
                stones.append(first - second)
                stones = sorted(stones)
        return stones[-1] if stones else 0


def main():
    self = Solution()
    # stones = [2,7,4,1,8,1]
    stones = [1]
    print(Solution.lastStoneWeight(self, stones))
main()