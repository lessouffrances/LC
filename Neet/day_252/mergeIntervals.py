class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(intervals) == 0: return []
        intervals.sort()

        merged_intervals = []
        merged_intervals.append(intervals[0])

        for i in range(1, len(intervals)):
            curr_start = intervals[i][0]
            curr_end = intervals[i][1]
            prev_start = merged_intervals[-1][0]
            prev_end = merged_intervals[-1][1]

            if curr_start <= prev_end:
                interval = [min(curr_start, prev_start), max(curr_end, prev_end)]
                merged_intervals.pop()
                merged_intervals.append(interval)
            else:
                merged_intervals.append(intervals[i])
        return merged_intervals
