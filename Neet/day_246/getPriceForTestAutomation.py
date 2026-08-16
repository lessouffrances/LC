# Let's design a critical component for a Test Automation Framework. 
# Our framework needs to verify the behavior of a system (like an e-commerce site) that has data changing over time. For example, 
# to validate a customer's invoice from last week, 
# our Test Agent must be able to query what the exact price of 
# a product was at the moment of purchase.
# To do this, the agent is given access to a 'Source of Truth' (SoT). 
# The SoT is a list of records sorted chronologically 
# by timestamp.

# Each record contains information (e.g., price) that is valid from its timestamp up to the timestamp of the next record.
# Your task is to write a function that takes a sorted list of input timestamps (representing the times to be queried) 
# and efficiently returns the correct record for each one.

# Assumptions:
# The SoT is a list of (timestamp, value) tuples, sorted by timestamp.
# The queries list (for the core problem) is also sorted by timestamp.

# Step 1:
#      confirm the understanding of the question
# Step 2:
#      discuss input/output
# SoT = [(3,4), (7，5)，(8,2),(10,5),(15,7),(20,4)]
# queries = [2,4,6,7,10,15,19,25,27]
# result = [None,4,4,5,5,7,7,4,4]

# example: ts: 2 => none, 
#          ts: 4 => 4
                
# condition? 
# lower_bound: is smaller or equal to the queried ts


# Approach 1: Binary Search
class SolutionBinarySearch(object):
    def get_queried_price(self, SoT, timestamps):
        if len(SoT) == 0:
            return [-1] * len(timestamps)
        
        if len(timestamps) == 0:
            return []

        n = len(timestamps)
        # loop thru all the queried ts
        res = []
        for i in range(n):
            queried_timestamp = timestamps[i]
            res.append(self.get_price_for_single_timestamp(SoT, queried_timestamp))
        return res

    # return the price
    def get_price_for_single_timestamp(self, SoT, timestamp):
        if len(SoT) == 0: return -1

        m = len(SoT)
        left, right = 0, m-1

        res = -1
        while left<=right:
            mid = (left+right) // 2
            if SoT[mid][0] <= timestamp:
                res = SoT[mid][1]
                left = mid+1
            else:
                right = mid-1 
        return res

# Approach 2: Two-pointer, Linear Scan
# length of timestamps: 10000
# length of sourceOfTruth: 1024  logM = 10
# time: n * logm = 10000 * 10 = 100000
# two pointers
# time: n + m = 11024
class SolutionTwoPointer(object):
    def get_queried_price(self, SoT, timestamps):
        if len(SoT) == 0:
            return [-1] * len(timestamps)
        
        if len(timestamps) == 0:
            return []

        n = len(timestamps)
        m = len(SoT)
        res = []
        j = 0

        # loop thru all the queried ts
        for i in range(n):
            queried_timestamp = timestamps[i]
            while j+1 < m and SoT[j+1][0] <= queried_timestamp:
                j += 1
            if SoT[j][0] <= queried_timestamp:
                res.append(SoT[j][1])
            else:
                res.append(-1)
        return res