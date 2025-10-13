class Solution:
    def camelMatch(self, queries, pattern):
        return [ Solution.matchesPattern(self, query, pattern) for query in queries ]
    
    def matchesPattern(self, query, pattern):
        queryLength, patternLength = len(query), len(pattern)
        queryIndex, patternIndex = 0, 0
        
        while patternIndex<patternLength:
            while queryIndex<queryLength and query[queryIndex] != pattern[patternIndex] and query[queryIndex].islower():
                queryIndex += 1
            
            if queryIndex == queryLength or query[queryIndex] != pattern[patternIndex]:
                return False
            queryIndex += 1
            patternIndex += 1
        
        while queryIndex<queryLength and query[queryIndex].islower():
            queryIndex += 1
        
        return queryIndex == queryLength
        
def main():
    self = Solution
    queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
    pattern = "FB"
    # [true, false, true, true, false]

    queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
    pattern = "FoBa"
    # [true, false, true, false, false]

    queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
    pattern = "FoBaT"
    # [false, true, false, false, false]

    Solution.camelMatch(self, queries, pattern)
    # print(Solution.matchesPattern(self, "FooBar", "FoBaT"))
main()