class Solution
{
    public:
    int expressiveWords(string s, vector<string>& words) 
    {
        unordered_map<char, int> sCounter = getCounter(s);
        vector<string> candidates;

        for (const auto & word : words) {
            bool isQualified = true;
            unordered_map<char, int> wCounter = getCounter(word);

            // first filter: same keys
            if (!sameKeys(wCounter, sCounter)) continue;

            // second filter: wCounter[key] > sCounter[key]
            for (const auto& [key, count] : wCounter) {
                if (wCounter[key] > sCounter[key]) {
                    isQualified = false;
                    break;
                }
            }

            if (isQualified) {
                candidates.push_back(word);
            }
        }

        vector<string> okCandidates;
        for (const auto& word : candidates) {
            bool isOk = true;
            int i = 0, j = 0;
            int i_Count = 1, j_Count = 1;
            int n = s.length(), m = word.length();

            while (i < n && j < m) {
                while (i+1 < n && s[i] == s[i+1]) {
                    i++; 
                    i_Count++;
                }
                while (j+1 < m && word[j] == word[j+1]) {
                    j++; 
                    j_Count++;
                }
                if (i_Count != j_Count && i_Count < 3) {
                    isOk = false;
                    break;
                }
                i++;
                j++;
                i_Count=1;
                j_Count=1;
            }
            if (i != n || j != m) {
                isOk = false;

            }
            if (isOk) {
                okCandidates.push_back(word);
            }
        }
        return okCandidates.size();
    }
    private:
    unordered_map<char, int> getCounter(const string& word)
    {
        unordered_map<char, int> counter;
        for (char c : word) {
            counter[c]++;
        }
        return counter;
    }

    bool sameKeys(unordered_map<char, int>& counter1, unordered_map<char, int>& counter2)
    {
        if (counter1.size() != counter2.size()) return false;
        for (const auto& [key, _ ] : counter1) {
            if (!counter2.count(key)) return false;
        }
        return true;
    }
};