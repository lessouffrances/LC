class Solution:
    def compress(self, chars) -> int:
        l, r = 0, 0
        
        while r<len(chars):
            char = chars[r]
            count = 0

            while r<len(chars) and chars[r] == char:
                r += 1
                count += 1
            
            chars[l] = char
            l += 1

            if count > 1:
                for digit in str(count):
                    chars[l] = digit
                    l += 1
        print(l)  
        print(chars)  
        return l

def main():
    self = Solution
    chars = ["a","a","b","b","c","c","c"] # "a2b2c3"
    # chars = ["a"] # "a"
    # chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"] # "ab12"
    Solution.compress(self, chars)
main()