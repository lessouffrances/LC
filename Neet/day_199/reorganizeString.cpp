class Solution 
{
    public:
    string reorganizeString(string s) 
    {
        if (s.length() == 0) return "";

        // build freqS
        unordered_map<char, int> freqS;
        for (char ch : s) {
            freqS[ch]++;
        }

        // with the most frequent ch on top
        // { count, ch }, for people who don't have hands on C++, 
        // specify format
        priority_queue<pair<int, char>> maxHeap;
        // push all pairs onto pq
        for (auto& [ch, count] : freqS) {
            maxHeap.push( {count, ch} );
        }

        string res = "";
        while (maxHeap.size()>=2) {
            auto [count1, ch1] = maxHeap.top();
            maxHeap.pop();
            auto [count2, ch2] = maxHeap.top();
            maxHeap.pop();

            res += ch1;
            res += ch2;

            if (count1 > 1) maxHeap.push( {count1-1, ch1 });
            if (count2 > 1) maxHeap.push( {count2-1, ch2 });
        }

        // should be one pair left
        if (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            if (count > 1) return "";
            res += ch;
        }
        return res;
    }
};
        