class Solution:
    def plusOne(self, digits):
        char = ""
        for num in digits:
            char += str(num)

        print(char)
        plusOneInteger = int(char) + 1
        res = list(str(plusOneInteger))

        for i in range(len(res)):
            res[i] = int(res[i])

        return res


        



def main():
    self = Solution
    digits = [1,2,3]
    print(Solution.plusOne(self, digits))
main()