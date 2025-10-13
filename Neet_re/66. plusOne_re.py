class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        integer = 0
        n = 0
        for i in range(len(digits) - 1, -1, -1):
            integer += digits[i] * (10 ** n)
            n += 1
        print(integer)

        integer = integer + 1
        integer = str(integer)

        res = []
        for s in integer:
            res.append(int(s))
        return res
            

def main():
    self = Solution()
    digits = [1, 0]
    Solution.plusOne(self, digits)
main()