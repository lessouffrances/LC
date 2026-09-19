class Solution 
{
    public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        if (s.length() == 0 || words.empty()) return {};

        int wordLen = words[0].length();
        int wordCount = words.size();
        int windowLen = wordLen*wordCount;
        int n = s.length();

        unordered_map<string, int> wordFreq;
        for (auto& w : words) wordFreq[w]++;

        vector<int> res;
        for (int i=0; i<wordLen; i++) {
            unordered_map<string, int> windowFreq;
            int left = i, count = 0;

            for (int right=i; right+wordLen<=n; right+=wordLen) {
                string word = s.substr(right, wordLen);
                if (wordFreq.count(word)) {
                    windowFreq[word]++;
                    count++;
                    while (windowFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == wordCount) res.push_back(left);
                } else {
                    windowFreq.clear();
                    count = 0;
                    left = right+wordLen;
                }
            }
        }
        return res;
    }
};