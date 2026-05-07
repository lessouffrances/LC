

class Solution 
{
    public:
    int maxNumberOfBalloons(string text) 
    {
        // build an empty map
        INSTANCE = "balloon";
        unordered_map<char, int> collector;
        for (char ch : INSTANCE) {
            collector[ch] = 0;
        }

        for (char ch : text) {
            if (collector.count(ch)) {
                collector[ch]++;
            } 
        }

        int minCount = INT_MAX;
        for (auto& [ch, count] : collector) {
            if (count == 0) return 0;
            if (ch == 'l' || ch == 'o') minCount = min(minCount, count/2);
            else minCount = min(minCount, count);
        }
        return minCount;
    }
};