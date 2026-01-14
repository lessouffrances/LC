class Solution {
    public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int res = 0;
        unordered_map<string, bool> checker;

        for (auto& word : words) {
            if (checker.count(word)) {
                if (checker[word]) {
                    res++;
                } 
                continue;
            }
            if (isSubsequence(word, s)) {
                checker[word] = true;
                res++;
            }
        }
        return res;
    }
    private:
    //returns trus if s is a subsequence of t
    bool isSubsequence(string s, string t)
    {
        int i = 0;
        for (char c : t) {
            if (i<s.size() && s[i] == c) {
                i++;
            }
        }
        return i == s.size();
    }
};