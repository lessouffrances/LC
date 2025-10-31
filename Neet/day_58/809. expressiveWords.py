from collections import Counter

class Solution:
    def expressiveWords(self, s, words) -> int:
        s_counter = dict(Counter(s))
        candidates = []

        for w in words:
            qualified = True
            w_counter = dict(Counter(w))

            # chars must be the same
            if w_counter.keys() != s_counter.keys():
                continue

            # check for headcounts for chars
            for key in w_counter.keys():
                if w_counter[key] > s_counter[key]:
                    qualified = False
                    continue
            
            if qualified:
                candidates.append(w)
        
        ok_candidates = []
        for w in candidates:
            ok = True
            i, j = 0, 0
            i_count, j_count = 1, 1

            while i < len(s) and j < len(w):
                while i+1 < len(s) and s[i] == s[i+1]:
                    i += 1
                    i_count += 1
                
                while j+1 < len(w) and w[j] == w[j+1]:
                    j += 1
                    j_count += 1
                
                if (i_count-j_count) != 0 and i_count < 3:
                    ok = False
                
                i, j = i+1, j+1
                i_count, j_count = 1, 1

            if i != len(s):
                ok = False
                
            if ok:
                ok_candidates.append(w)
        return len(ok_candidates)
    
def main():
    solution = Solution()
    s = "heeellooo"
    words = ["hello", "hi", "helo"] #1 only "hello""

    # s = "zzzzzyyyyy"
    # words = ["zzyy","zy","zyy"] #3 

    # s = "abcd" 
    # words = ["abc"] #0

    s = "sass"
    words = ["sa"] #0

    # s = "aaa"
    # words = ["aaaa"] #0
    solution.expressiveWords(s, words)
main()
