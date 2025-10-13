class Solution:
    def hIndex(self, citations) -> int:

        n = len(citations)
        citations = sorted(citations)
        l, r = 0, n-1
        
        while l <= r:
            mid = (int)(l + (r-l)/2)
            if citations[mid] < n-mid:
                l = mid+1
            else:
                r = mid-1

        return n-l

    

def main():
    self = Solution()
    # citations = [3, 0, 6, 1, 5]
    citations = [1, 3, 1]
    print(Solution.hIndex(self, citations))

main()