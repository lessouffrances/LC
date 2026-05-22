class Solution 
{
    public:
    int maxNumberOfBalloons(string text) 
    {
        if (text.length() == 0) return 0;

        string INSTANCE = "balloon";
        unordered_map<char, int> balloonFreq;
        for (char ch : INSTANCE) {
            balloonFreq[ch]++;
        }

        unordered_map<char, int> textFreq;
        for (char ch : text) {
            textFreq[ch]++;
        }

        int res = INT_MAX;
        for (auto& [ch, count] : balloonFreq) {
            if (textFreq.count(ch)) {
                res = min(textFreq[ch] / balloonFreq[ch], res);
            } else {
                return 0;
            }
        }
        return res;
    }
};