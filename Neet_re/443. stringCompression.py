class Solution:
    def compress(self, chars) -> int:
        l, r = 0, 0
        count = 0

        while r<len(chars):
            char = chars[r]
            count = 0

            while r<len(chars) and chars[r] == char:
                count += 1
                r += 1
            
            chars[l] = char
            l += 1
            if count>1:
                for digit in str(count):
                    chars[l] = digit
                    l += 1
        print(chars)
        return l

def main():
    self = Solution
    chars = ["a","a","b","b","c","c","c"]

    Solution.compress(self, chars)
main()