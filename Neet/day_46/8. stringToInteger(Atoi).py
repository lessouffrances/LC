class Solution:
    def myAtoi(self, s: str) -> int:
        index = 0
        sign = False
        for i, char in enumerate(s):
            if char == " ":
                index = len(s)
                continue
            else:
                index = i
                break
        s = s[ index : ]
        print(f"string after getting rid of whitespaces: {s}", end="\n")

        if len(s) > 0 and s[0] in ["+", "-"]:
            print("Y")
            sign = True
            real_sign = s[0]
            s = s[ 1 : ]
        print(f"string after getting rid of signs: {s}", end="\n")

        for i, char in enumerate(s):
            if ord(char) == 48:
                index = len(s)
                continue
            else:
                index = i
                break
        s = s[ index : ]
        print(f"string after getting rid of 0s: {s}", end="\n")

        for i, char in enumerate(s):
            if ord(char) >= 48 and ord(char) <= 57:
                index = len(s)
                continue
            else:
                index = i
                break
        s = s[ : index ]
        print(f"string after getting rid of symbols: {s}", end="\n")

        if len(s) == 0:
            return 0

        s = int(s)
        if sign and real_sign == "-":
            s = -s

        if s > 2**31-1:
            return 2**31-1
        elif s < -2**31:
            return -2**31
        
        return s
    
def main():
    solution = Solution()
    s = "42" #42
    # s = " -042" #-42
    # s = "1337c0d3" #1337
    # s = "0-1" #0
    s = "-10000000000000"
    print(solution.myAtoi(s))
main()