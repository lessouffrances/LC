class Solution(object):
    def maximizeFrequency(self, values, k):
        num_of_k = 0
        distinct_set = set()

        for val in values:
            if val == k:
                num_of_k += 1
            else:
                distinct_set.add(val)
        
        max_gain = 0
        # per val per subarray
        for val in distinct_set:
            curr = 0
            for i in range(len(values)):
                if values[i] == val:
                    curr += 1
                elif values[i] == k:
                    curr -= 1
                if curr < 0:
                    curr = 0
                max_gain = max(max_gain, curr)
        
        return num_of_k + max_gain