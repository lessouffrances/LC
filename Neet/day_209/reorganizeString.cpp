class Solution 
{
    public:
    string reorganizeString(string s) 
    {
        if (s.length() == 0) return "";
        priority_queue<pair<int, char>> maxHeap;

        unordered_map<char, int> freq;
        // build freq
        for (char ch : s) {
            freq[ch]++;
        }

        for (auto& [ch, count] : freq) {
            maxHeap.push( {count, ch} );
        }

        string res = "";
        while (maxHeap.size() >= 2) {
            auto [count1, ch1] = maxHeap.top();
            maxHeap.pop();
            auto [count2, ch2] = maxHeap.top();
            maxHeap.pop();

            res += ch1;
            res += ch2;

            if (count1 > 1) maxHeap.push( {count1-1, ch1} );
            if (count2 > 1) maxHeap.push( { count2-1, ch2} );
        }

        // we expect there is only one char left
        if (maxHeap.size() > 1 || maxHeap.top().first > 1) return "";
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            res += ch;
        }
        return res;
    }
};