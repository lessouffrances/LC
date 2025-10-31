from collections import Counter
from statistics import quantiles
class Solution:
    def expressiveWords(self, s, words) -> int:
        # check if word in words are the same set as s and the counts are less than that
        s_counter = Counter(s)
        candidates = []

        for word in words:
            word_counter = Counter(word)
            diff = s_counter - word_counter
            if s_counter.keys() == word_counter.keys() and all (v>0 for v in diff.values()):
                candidates.append(word)

        print(candidates)

        qualified_candidates = []
        for word in candidates:
            # i in shorter word, j in longer s
            print(f"The processed word is {word}.")
            qualified = True
            i, j = 0, 0
            while i < len(word) and j<len(s):
                curr_count_i, curr_count_j = 1, 1
                while i<len(word)-1 and word[i] == word[i+1]:
                    i += 1
                    curr_count_i += 1
                while j<len(s)-1 and s[j] == s[j+1]:
                    j += 1
                    curr_count_j += 1

                diff = curr_count_j-curr_count_i
                print(f"The i is {i} and j is {j}.")
                print(f"The curr_count_i is {curr_count_i}, the curr_count_j is {curr_count_j}.")
                if diff != 0 and curr_count_j < 3:
                    qualified = False
                    break
                i, j = i+1, j+1
            
            if j < len(s):
                qualified = False
            
            if qualified:
                qualified_candidates.append(word)
            print(qualified_candidates)
        return len(qualified_candidates)

                
def main():
    solution = Solution()
    s = "heeellooo"
    words = ["hello", "hi", "helo"] #1 only "hello""

    s = "zzzzzyyyyy"
    words = ["zzyy","zy","zyy"] #3 

    s = "abcd" 
    words = ["abc"] #0

    s = "sass"
    words = ["sa"] #0

    s = "aaa"
    s = ["aaaa"]
    solution.expressiveWords(s, words)
main()
