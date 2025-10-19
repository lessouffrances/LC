from collections import Counter

class Solution:
    def countAndSay(self, n: int) -> str:
        
        def helper(numbers):
            res = ""
            hash_map = dict(Counter(numbers))
            for key, value in hash_map.items():
                res += str(value)+str(key)
            return res
        
        for num in range(1, n+1):
            if num == 1:
                curr_output = "1"
            else:
                curr_output = list(curr_output)
                print(curr_output)
                curr_output = helper(curr_output)
        
        print(helper([11]))
        return curr_output




def main():
    solution = Solution()
    n = 4 #1211
    # n = 1 #1
    n = 5 #111221
    print(solution.countAndSay(n))



main()