from collections import Counter
class Solution:
    def topKFrequent(self, nums, k: int):
        counter = Counter(nums)
        print(counter)
        res = []

        counter = counter.most_common()
        print(counter)

        for i in range(k):
            res.append(counter[i][0])
        print(res)
        return res


            


def main():
    self = Solution
    nums = [1,1,1,2,2,3]
    k = 2
    nums = [3, 0, 1, 0]
    k = 1
    Solution.topKFrequent(self, nums, k)
main()