class Solution:
    def selectionSort(self, arr):
        if len(arr) <= 1:
            print(arr)
            return arr
        
        for i in range(len(arr)-1):
            minIndex = i
            for j in range(i+1, len(arr)):
                if arr[j]<arr[minIndex]:
                    minIndex = j
            temp = arr[i]
            arr[i] = arr[minIndex]
            arr[minIndex] = temp
        print(arr)
        return arr

def main():
    self = Solution
    arr = [12, 11, 13, 5, 6]
    arr = [0, -3]
    Solution.selectionSort(self, arr)
main()