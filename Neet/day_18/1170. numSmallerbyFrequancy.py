# This approach is not effeicent beacause it does not using BinarySearch
class Solution:
    def numSmallerByFrequency(self, queries, words):
        res = []
        for query in queries:
            count = 0
            for word in words:
                if Solution.smallestFrequency(self, query)<Solution.smallestFrequency(self, word):
                    count += 1
            res.append(count)
        return res
    
    def smallestFrequency(self, string):
        sortedString = sorted(string)
        count = 1
        for i in range(len(sortedString)):
            if (i+1)<len(sortedString) and sortedString[i+1] == sortedString[i]:
                count += 1
            else:
                break
        return count
    
def main():
    self = Solution
    queries = ["cbd"]
    words = ["zaaaz"] # output = [1]

    queries = ["bbb","cc"]
    words = ["a","aa","aaa","aaaa"] # output = [1, 2]

    queries = ["bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"]
    words = ["aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"]

    Solution.numSmallerByFrequency(self, queries, words)
    print(Solution.smallestFrequency(self, "aaabbb"))
    # print(Solution.binarySearch(self, 3, [1, 2, 4, 6, 7]))
main()