from itertools import combinations
class Solution:
    def threeSumClosest(self, nums, target):
        comboList = list(combinations(nums, 3))

        hashMap = {}
        for combo in comboList:
            hashMap[combo] = abs(sum(combo)-target)


        sortedHashMap = dict(sorted(hashMap.items(), key=lambda item : item[1]))

        valueList = []
        for (key, val) in sortedHashMap.items():
            valueList.append(val)
        
        print(next(sum(k) for k, v in sortedHashMap.items() if v == valueList[0]))
        return next(sum(k) for k, v in sortedHashMap.items() if v == valueList[0])
        


def main():
    self = Solution
    nums = [-1,2,1,-4]
    target = 1
    Solution.threeSumClosest(self, nums, target)
main()