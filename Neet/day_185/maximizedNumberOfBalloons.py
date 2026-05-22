class Solution(object):
    def maxNumberOfBalloons(self, text):
        if not text:
            return 0

        res = float('inf')
        for ch in "balloon":
            count = text.count(ch)
            multi = count / "balloon".count(ch)
            res = min(res, multi)
        return res
