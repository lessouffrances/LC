class Solution 
{
    public:
    bool equalFrequency(string word) 
    {
        if (word.length() == 0) return false;

        vector<int> charCounter(26, 0);
        for (char ch : word) {
            charCounter[ch-'a']++;
        }

        for (int i=0; i<26; i++) {
            if (charCounter[i] == 0) continue;

            // simulate decrese by 1
            charCounter[i]--;
            // check if all remaining numbers (except 0s) are equal
            unordered_set<int> numSet;
            for (int i=0; i<26; i++) {
                if (charCounter[i] == 0) continue;
                numSet.insert(charCounter[i]);
            }
            if (numSet.size() == 1) return true;
            charCounter[i]++; // backtrack
        }
        return false;
    }
};