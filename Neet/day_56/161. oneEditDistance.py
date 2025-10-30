class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        m, n = len(s),  len(t)

        if abs(m-n)>1:
            return False

        count = 0
        i, j = 0, 0

        while i<m and j<n:
            # if two indexed chars not equal
            if s[i] != t[j]:
                # if already count == 1, return false
                if count == 1:
                    return False
                # if s is longer, delete
                if m > n:
                    i += 1
                # if t is longer, delete
                elif m < n:
                    j += 1
                # if two strings lengths equal, replace
                else:
                    i, j = i+1, j+1
                count += 1

            # if two indexed chars equal
            else:
                i, j = i+1, j+1
        
        if i<m or j<n:
            count += 1
        return count == 1

                 


def main():
    solution = Solution()
    s = "ab"
    t = "acb"

    s = ""
    t = ""
    solution.isOneEditDistance(s, t)
main()