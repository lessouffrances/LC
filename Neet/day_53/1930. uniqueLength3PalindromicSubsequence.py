class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        if len(s) < 3:
            return 0
        if len(s) == 3 and s[0] == s[-1]:
            return 1
        hash_set = set()

        left, mid, right = 0, 1, 2
        while left < len(s)-2:
            while right < len(s):
                if s[right] == s[left]:
                    while mid < right:
                        curr_palindrome = s[left]+s[mid]+s[right]
                        print(f"curr palindrome is {curr_palindrome}.", end="\n")
                        if curr_palindrome not in hash_set:
                            hash_set.add(curr_palindrome)
                        mid += 1
                    print(f"mid is {mid}", end="\n")
                right += 1
            
            while s[left] == s[left+1] and left+1 < len(s)-3:
                left += 1
            left += 1  # Increment left to move to the next character
            mid = left+1
            right = mid+1
            
        
        print(hash_set)
        print(len(hash_set))
        return len(hash_set)
        

def main():
    solution = Solution()
    s = "aabca" #3
    # s = "ahftr" #0
    # s = "bbcbaba" #4
    # s = "adc" #0

    solution.countPalindromicSubsequence(s)
main()