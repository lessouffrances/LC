class Solution:
    def countAndSay(self, n):
        def helper(say):
            res = ""
            left, right = 0, 0
            curr_count = 0

            while left < len(say):
                while right < len(say) and say[right] == say[left]:
                    right += 1
                    curr_count += 1
            
                res += str(curr_count)+say[left]
                left = right
                curr_count = 0
            return res
        print(helper("1"))
        print(helper("11"))
        print(helper("1211"))

        for i in range(n):
            if i == 0:
                curr_say = "1"
                continue
            else:
                curr_say = helper(curr_say)
                print(f"The curr_say for {i} is {curr_say}.", end="\n")
        return curr_say


def main():
    solution = Solution()
    # n = 4 #1211
    # n = 1 #1
    # n = 5 #111221
    n = 6 #312211
    solution.countAndSay(n)
main()