class Solution:
    def twoSum(self, numbers, target):
        res = []

        for i, number in enumerate(numbers):
            diff = target-number
            index = Solution.binarySearch(self, numbers, diff)
            if index != -1 and index != i:
                res.append(i+1)
                res.append(index+1)
                break
        res = sorted(res)
        print(res)
        return res

    def binarySearch(self, nums, target):
        l, r = 0, len(nums)-1

        while l<=r:
            mid = (l+r)//2
            if target<nums[mid]:
                r = mid-1
            elif target>nums[mid]:
                l = mid+1
            else:
                return mid
        return -1



def main():
    self = Solution
    numbers = [2,7,11,15] 
    target = 9

    numbers = [12,83,104,129,140,184,199,300,306,312,321,325,341,344,349,356,370,405,423,444,446,465,471,491,500,506,508,530,539,543,569,591,606,607,612,614,623,627,645,662,670,685,689,726,731,737,744,747,764,773,778,787,802,805,811,819,829,841,879,905,918,918,929,955,997]
    target = 789
    Solution.twoSum(self, numbers, target)
    # print(Solution.binarySearch(self, [1, 2, 3, 4, 5], 6))
main()