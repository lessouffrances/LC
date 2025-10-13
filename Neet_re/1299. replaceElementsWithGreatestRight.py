class Solution:
    def replaceElements(self, arr: list[int]) -> list[int]:
        rightMax = -1
        for i in range(len(arr) - 1, -1, -1):
            newMax = max(rightMax, arr[i])
            arr[i] = rightMax
            rightMax = newMax
        return arr

def main():
    self = Solution()
    arr = [17,18,5,4,6,1]
    Solution.replaceElements(self, arr)
main()