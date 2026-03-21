



class Solution 
{
    public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        if (words.empty()) return {};

        auto [changed, nextWords] = process(words);
        while (changed) {
            words = nextWords;
            tie(changed, nextWords) = process(words);
        }

        return words;
    }

    private:
    // return if the process is still effective and the result
    pair<bool, vector<string>> process(vector<string>& words)
    {
        if (words.empty()) return {};
        int n = words.size();
        unordered_set<int> toRemove;

        for (int i=1; i<n; i++) {
            if (isAnagram(words[i], words[i-1])) {
                toRemove.insert(i);
            }
        }

        // if the process is not effective, return
        if (toRemove.empty()) return { false, words };

        vector<string> res;
        for (int i=0; i<n; i++) {
            if (!toRemove.count(i)) {
                res.push_back(words[i]);
            }
        }
        return { true, res };
    }

    bool isAnagram(const string& s, const string& t)
    {
        if (s.length() != t.length()) return false;
        int n = s.length();

        vector<int> sCounter(26, 0);
        vector<int> tCounter(26, 0);

        for (int i=0; i<n; i++) {
            sCounter[s[i]-'a']++;
            tCounter[t[i]-'a']++;
        }
        return sCounter == tCounter;
    }
};