class Solution(object):
    def maxNumberOfBalloons(self, text):
        if not text:
            return 0

        res = float("inf")
        for ch in "balon":
            count = text.count(ch)
            mult = count / "balloon".count(ch)
            res = min(res, mult)
        return res
    