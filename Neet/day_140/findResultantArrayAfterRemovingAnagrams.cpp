



// Time: O(N * M), where N is the size of the array and M is the length of the word
// Space: O(N * M) 
class Solution 
{
    public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        if (words.empty()) return {};
        int n = words.size();

        vector<string> res = { words[0] };
        for (int i=1; i<n; i++) {
            // the current words is NOT an anagram for the last word in res,
            // it remain alive, push back
            if (!isAnagram(words[i], res.back())) {
                res.push_back(words[i]);
            }
        }
        return res;
    }

    private:
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