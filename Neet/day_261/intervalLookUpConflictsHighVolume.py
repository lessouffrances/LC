# Problem
# Given one candidate interval and a list of existing intervals, determine whether the candidate conflicts 
# with any existing interval.
# All intervals use half-open semantics [start, end): an interval ending at time t does not conflict with one starting at t.

# Function Contract
# Implement hasIntervalConflict(candidate, intervals) where every interval is [start, end] with start < end.
# Negate non-overlap
# Examples
# candidate = [4, 7]
# intervals = [[1, 3], [7, 9]]
# output = false

# candidate = [4, 7]
# intervals = [[1, 5], [8, 9]]
# output = true

# 如何判断[left1,right1)   和  [left2, right2) 有交叉？
    
#     不重叠的情况1: right1 <= left2
#     不重叠的情况1: right2 <= left1

def judgeConflict(candidate: list[int], intervals: list[list[int]]) -> bool:
    def judgeTwoIntervalConflict(candidate: list[int], interval: list[int]) -> bool:
        left1, right1 = candidate
        left2, right2 = interval
        if right1 <= left2 or right2 <= left1:
            return False
        else:
            return True

    for interval in intervals:
        if judgeTwoIntervalConflict(candidate, interval):
            return True
    return False

print(judgeConflict([4, 7],[[1, 3], [7, 9]]))
print(judgeConflict([4, 7],[[1, 5], [8, 9]]))

'''
做法：
    1. 区间合并(会排序)
        [2,4],[1,3], [8,10],[5,7]
        合并后： [1,4),[5,7),[8,10)
    2. 合并之后，如何查询一个区间和合并之后的区间有交叉？
        算法： 二分
        搜索目标： 找满足有交叉的区间的第一个
        
        调整范围：
            当前candidate 和  interval[mid]有交叉，返回True
            如果candidate的right <= 当前区间的左端点：
                往左找
            否则：
                往右找
'''
class IntervalConflict:
    def __init__(self,intervals:list[list]):
        self.intervals = self.mergeIntervals(intervals)
        # print(self.intervals)

    def mergeIntervals(self,intervals:list[int]) -> list: # nlogn
        if intervals == []:
            return []
        intervals.sort()  # [1,3],[2,4],[5,7], [8,10]
        res = [intervals[0]] # 第一个区间先放入答案数组中 res = [[1,3]]

        for left,right in intervals[1:]:
            if res[-1][1] >= left: # 需要合并 [1,3] [2,4] 合并
                res[-1][1] = max(res[-1][1], right)
            else: # 不发生重叠
                res.append([left,right])
        return res

    def judgeTwoIntervalConflict(self,candidate: list[int], interval: list[int]) -> bool:
        left1, right1 = candidate
        left2, right2 = interval
        if right1 <= left2 or right2 <= left1:
            return False
        else:
            return True
    def query(self,candidate:list[int]) -> bool: # logn
        # 二分查询
        left,right = 0,len(self.intervals) - 1
        while left <= right:
            mid = (left + right) // 2
            if self.judgeTwoIntervalConflict(candidate, self.intervals[mid]):
                return True # 有交叉
            elif candidate[1] <= self.intervals[mid][0]: # 区间 在 mid区间的左边
                right = mid - 1 # [left,mid-1]
            else:
                left = mid + 1  # [mid+1,right]
        return False

intervalConflict = IntervalConflict([[2,4],[1,3],[8,10],[5,7]])
print(intervalConflict.query([9,15]))