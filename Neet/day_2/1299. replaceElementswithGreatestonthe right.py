class Solution:
    def replaceElements(self, arr: list[int]) -> list[int]:
        # initial max = -1 
        # reverse iteration 
        # new max = max(old_max, arr[i])

        rightMax = -1

        for i in range(len(arr) - 1, -1, -1):
            newMax = max(rightMax, arr[i])
            arr[i] = rightMax
            rightMax = newMax
        print(arr)
        return arr


def main():
    self = Solution()
    arr = [17, 18, 5, 4, 6, 1]
    Solution.replaceElements(self, arr)
main()

# new[0] = max(arr[1:5])
# new[1] = max(arr[2:5])
# new[2] = max(arr[3:5])
# O(n^2)

# reverse iterate 
# new[5] = -1 base case
#  18   6  6  6  1  -1
# [17, 18, 5, 4, 6, 1] 
# O(n)
      