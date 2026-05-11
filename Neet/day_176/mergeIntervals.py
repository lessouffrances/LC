# intervals.sort()                          # default: sort by first element, then second
# intervals.sort(key=lambda x: x[0])       # sort by first element only
# intervals.sort(key=lambda x: (x[0], x[1])) # sort by first, then second
# intervals.sort(reverse=True)              # descending
# intervals.sort(key=lambda x: x[0], reverse=True)  # descending by first element

class Solution(object):
    def merge(self, intervals):
        if not intervals:
            return []
        
        intervals.sort()

        merged_intervals = []
        merged_intervals.append(intervals[0])
        prev_start = intervals[0][0]
        prev_end = intervals[0][1]

        for i in range(len(intervals)):
            start = intervals[i][0]
            end = intervals[i][1]
            prev_start = merged_intervals[-1][0]
            prev_end = merged_intervals[-1][1]

            if start <= prev_end:
                merged = [min(prev_start, start), max(end, prev_end)]
                merged_intervals.pop()
                merged_intervals.append(merged)
            else:
                merged_intervals.append(intervals[i])
        
        return merged_intervals
            
        