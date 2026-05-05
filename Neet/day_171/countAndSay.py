class Solution(object):
    def countAndSay(self, n):
        prev = "1"
        for _ in range(n-1):
            prev = self.countAndSayHelper(prev)
        return prev
    
    def countAndSayHelper(self, s):
        if len(s) == 0:
            return ""
        
        deck = [] # [num, count]
        for i in range(len(s)):
            if deck and deck[-1][0] == s[i]:
                deck[-1][1] += 1
            else:
                deck.append( [s[i], 1] )

        res = ""
        while deck:
            num, count = deck[-1]
            deck.pop()

            foo = str(count) + num
            res = foo + res
        return res