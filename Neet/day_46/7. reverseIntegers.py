class Solution:
    def reverse(self, x: int) -> int:
        if (x > (2**31)-1) or (x < -2**31):
            return 0
        sign = False
        x_str = str(x)

        if x_str[0] == "-":
            sign = True
            x_str = x_str[1: ]
        index = 0
        x_str = x_str[::-1]
        for i, char in enumerate(x_str):
            if char == "0":
                continue
            else:
                index = i
                break
        if index:
            x_str = x_str[index: ]
        if sign:
            x_str = "-" + x_str  

        res = int(x_str)
        if (res > (2**31)-1) or (res < -2**31):
            return 0
        return res

def main():
    solution = Solution()
    # x = 123 #321
    # x = -123 #-321
    x = 120 #21
    solution.reverse(x) 
main()