class Solution 
{
    public:
    int maxNumberOfBalloons(string text) 
    {
        if (text.length() == 0) return 0;

        // distinct
        unordered_set<char> instances = {'b', 'a', 'l', 'o', 'n'};
        // construct a freq map
        unordered_map<char, int> freq;
        for (char ch : instances) {
            freq[ch] = 0;
        }

        for (char ch : text) {
            if (instances.count(ch)) {
                freq[ch]++;
            }
        }

        int res = INT_MAX;
        for (auto& [ch, count] : freq) {
            if (ch == 'l' || ch == 'o') {
                count /= 2; // floor division
            } 
            res = min(res, count);
        }
        return res;
    }
};