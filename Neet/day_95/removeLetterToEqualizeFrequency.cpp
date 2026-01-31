class Solution 
{
    public:
    bool equalFrequency(string word) 
    {
        if (word.length() == 0) return false;
        int n = word.length();

        vector<int>charFreq(26, 0);

        for (char ch : word) {
            charFreq[ch-'a']++;
        }

        for (int i=0; i<26; i++) {
            if (charFreq[i] == 0) continue;

            // simulate decrese by 1
            charFreq[i]--;

            // check if all remainings are equal
            unordered_set<int> freqs;
            for (int count : charFreq) {
                if (count > 0) {
                    freqs.insert(count);
                }
            }
            if (freqs.size() == 1) return true;
            // backtrack
            charFreq[i]++;
        }
        return false;
    }
};