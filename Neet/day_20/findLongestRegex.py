class Solution:
    def findLongestRegex(x, y, z):
        charMap = {}  # To store char3 as key and its index as value
        for idx, (char1, char2, char3) in enumerate(zip(x, y, z)):
            if (char1 != char3) and (char2 != char3):
                charMap[char3] = idx  # Map char3 to its index
        
        print("HashMap of candidates:", charMap)



def main():
    self = Solution
    x = "AERB"
    y = "ATRC"
    z = "AGCB"
    Solution.findLongestRegex(x, y, z)


main()