class Solution:
    def ipToCIDR(self, ip: str, n: int):
        # string => list of integers [255, 0, 0, 7]
        ipList = ip.split(".")
        ipListInt = []
        for str in ipList:
            ipListInt.append(int(str))
        print(ipListInt)

        # deal with the addition 
        i = len(ipListInt)-1
        while i >= 0 and n > 0:
            if (ipListInt[i] + n) > 255:
                n -= (255 - ipListInt[i])
                ipListInt[i] = 255
            else:
                ipListInt[i] += n
                n = 0
            i -= 1
        print(ipListInt)




def main():
    self = Solution
    ip = "255.0.0.7"
    n = 10
    Solution.ipToCIDR(self, ip, n)
main()