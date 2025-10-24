class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        curr_set = set()
        max_length = 0
        
        while right < len(s):
            if s[right] not in curr_set:
                curr_set.add(s[right])
                right += 1
            else:
                max_length = max(max_length, right-left)
                curr_set.clear()
                left += 1
                right = left

        max_length = max(max_length, right-left)
        print(max_length)
                


def main():
    solution = Solution()
    s = "abcabcbb" #3
    s = "bbbbb" #1
    s = "pwwkew" #3
    s = " " #1
    s = "dvdf" #3
    solution.lengthOfLongestSubstring(s)
main()