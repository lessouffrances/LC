class Solution:
    def jobScheduling(self, startTime, endTime, profit) -> int:
        # bundle the intervals
        intervals = []
        for i in range(len(profit)):
            interval = [startTime[i], endTime[i], profit[i]]
            intervals.append(interval)
        print(intervals)

        # sort on endTime
        intervals.sort(key=lambda x:x[1])
        print(intervals)
        
        sorted_profit = []
        for interval in intervals:
            sorted_profit.append(interval[2])
        print(sorted_profit)


        def findPrevCompatible(n):
            left, right = 0, n-2

            while left<=right:
                mid = (left+right)//2
                if intervals[mid][1] <= intervals[n-1][0]:
                    left = mid+1
                else:
                    right = mid-1
            return left

        # Recurrence:
        # max of inclusion of interval i and exclusion of interval i
        # OPT[i] = max( OPT[i-1], OPT[ previousCompatible ] + v_i )
        dp = [ 0 for _ in range(len(profit)+1) ]
        dp[0] = 0

        for i in range(1, len(dp)):
            dp[i] = max( dp[i-1], sorted_profit[i-1]+dp[findPrevCompatible(i)] )
        
        return max(dp)
        

def main():
    solution = Solution()
    startTime = [1,2,3,3]
    endTime = [3,4,5,6]
    profit = [50,10,40,70]
    #120

    startTime = [1,2,3,4,6]
    endTime = [3,5,10,6,9]
    profit = [20,20,100,70,60]
    #150

    # startTime = [1,1,1]
    # endTime = [2,3,4]
    # profit = [5,6,4]
    # #6
    solution.jobScheduling(startTime, endTime, profit)
main()
        