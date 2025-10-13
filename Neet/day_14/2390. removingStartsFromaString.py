class Solution:
    def removeStars(self, s: str) -> str:
        stack = []

        for char in s:
            if char != "*":
                stack.append(char)
            else:
                stack.pop()

        res = "".join(stack)
        print(res)
        return res
        


def main():
    self = Solution
    s = "leet**cod*e"
    # s = "erase*****"
    Solution.removeStars(self, s)
main()