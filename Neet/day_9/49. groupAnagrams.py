class Solution:
    def groupAnagrams(self, strs):
        res = defaultdict(list) # mapping charCount to list of Anagrams

        for str in strs:
            count = [0] * 26

            for char in str:
                count[ord(char) - ord("a")] += 1
            
            res[tuple(count)].append(str)

        return res.values()


def main():
    self = Solution()
    strs = ["eat","tea","tan","ate","nat","bat"]
    print(Solution.groupAnagrams(self, strs))

main()





