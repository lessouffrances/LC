class Solution:
    def twoSum(self, numbers, target):
        def binarySearch(left, right):
            while left<=right:
                mid = (left+right)//2

                if numbers[mid] == diff:
                    return mid
                elif numbers[mid] > diff:
                    right = mid-1
                else:
                    left = mid+1
            return -1

        i = 0
        while i < len(numbers):
            diff = target-numbers[i]
            index_2 = binarySearch(i+1, len(numbers)-1)
            if index_2 != -1:
                return [i+1, index_2+1]
            else:
                i+=1
        
        return -1

def main():
    solution = Solution()
    numbers = [2,7,11,15]
    target = 9 #[1, 2]

    numbers = [2,3,4]
    target = 6 #[1, 3]

    # numbers = [-1,0]
    # target = -1 #[1, 2]

    print(solution.twoSum(numbers, target))
main()
        