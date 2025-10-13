class Solution:
    def replaceElements(self, arr):
        temp = [0] * len(arr)
        temp[-1] = -1

        for i in range(len(arr)-2, -1, -1):
            if arr[i+1] > temp[i+1]:
                temp[i] = arr[i+1]
            else:
                temp[i] = temp[i+1]
        
        arr = temp
        return arr
        
        
    
def main():
    self = Solution
    arr = [17,18,5,4,6,1]
    # arr = [400]
    print(Solution.replaceElements(self, arr))




main()
