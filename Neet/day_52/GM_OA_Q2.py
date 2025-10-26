# Given an array of integers, and there are 3 tiles, each tile can shade 2 adjacent numbers.
# The tile cannot be placed partially outside the array.
# return the maximum result that you can get from this array.

class Solution:
    def maximumTiled(self, A):
        n = len(A)
        pair_sum = []
        for i in range(1, n):
            curr_pair_sum = A[i]+A[i-1]
            pair_sum.append(curr_pair_sum)
        
        dp = [ [0]*4 for _ in range(len(pair_sum)) ]
        # for row in dp:
        #     print(row, end="\n")
        # print("\n\n")

        for i in range(len(pair_sum)):
            for t in range(4):
                if i <= 1:
                    dp[i][t] = max(pair_sum[: i+1])
                if t == 0:
                    dp[i][t] = 0
                else:
                    if t == 1:
                        dp[i][t] = max(pair_sum[: i+1])
                    else:
                        dp[i][t] = max(pair_sum[i]+dp[i-2][t-1], dp[i-1][t])
                    
        
        for row in dp:
            print(row, end="\n")
        print("\n\n")


    

def main():
    solution = Solution()
    A = [5, 3, 8, 2, 7, 1] #26 [5,3], [8,2], [7,1]
    A = [1, 2, 3, 4, 5] #14
    # A = [1, 2, 3, 4, 5, 6, 7] #27
    # A = [10, 1, 1, 1, 10, 1, 1, 1, 10] #33 
    solution.maximumTiled(A)
main()