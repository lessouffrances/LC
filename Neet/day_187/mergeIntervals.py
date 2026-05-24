class Solution(object):
    def merge(self, intervals):
        if not intervals or len(intervals) == 1:
            return intervals
        
        intervals.sort()

        n = len(intervals)
        merged_intervals = []
        merged_intervals.append(intervals[0])

        for i in range(1, n):
            curr_start, curr_end = intervals[i][0], intervals[i][1]

            if curr_start <= merged_intervals[-1][1]:
                prev_start, prev_end = merged_intervals[-1][0], merged_intervals[-1][1]
                merged_intervals.pop()
                merged = [ min(curr_start, prev_start), max(curr_end, prev_end) ]
                merged_intervals.append(merged)
            else:
                merged_intervals.append(intervals[i])
        
        return merged_intervals



        