


// Time: O(N logN)
// Space: O(1)
class Solution 
{
    public:
    string frequencySort(string s) 
    {
        if (s.length() == 0) return "";

        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b){
            return a.second > b.second; // higher freq first
        });

        string res = "";
        for (auto& [ch, count] : freqVec) {
            res.append(count, ch);
        }
        return res;
    }
};