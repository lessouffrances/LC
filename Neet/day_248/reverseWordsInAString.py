class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0: return ""

        words = s.split()
        reversed_words = words[::-1]
        return " ".join(reversed_words)

