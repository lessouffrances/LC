class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        integer = 0
        n = 0
        for i in range(len(digits) -1, -1, -1):
            integer += (digits[i] * (10 ** n))
            n += 1
        integer = integer + 1
        
        integer = str(integer)

        lst = []
        for num in integer:
            num = int(num)
            lst.append(num)
        return lst

def main():
    self = Solution()
    digits = [9, 9, 9]
    # integer = 0
    # 0 + 9*10^0 = 9
    # 9 + 9*10^1 = 99
    print(Solution.plusOne(self, digits))


main()
        