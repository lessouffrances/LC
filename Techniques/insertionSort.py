class Solution:
    def insertionSort(self, arr):
        ############### sort in ascending order ##############
        # if len(arr)<=1:
        #     print(arr)
        #     return arr

        # for i in range(1, len(arr)):
        #     for j in range(i-1, -1, -1):
        #         if arr[j]>arr[j+1]:
        #             temp = arr[j]
        #             arr[j] = arr[j+1]
        #             arr[j+1] = temp
        #         else:
        #             break
        # print(arr)
        # return arr
    
        ############### sort in descending order ##############
        if len(arr)<=1:
            print(arr)
            return arr

        for i in range(1, len(arr)):
            for j in range(i-1, -1, -1):
                if arr[j]<arr[j+1]:
                    temp = arr[j]
                    arr[j] = arr[j+1]
                    arr[j+1] = temp
                else:
                    break
        print(arr)
        return arr


def main():
    self = Solution
    arr = [12, 11, 13, 5, 6]
    arr = []
    arr = [12, 13]
    arr = [13, 12 ,13]
    Solution.insertionSort(self, arr)
main()


