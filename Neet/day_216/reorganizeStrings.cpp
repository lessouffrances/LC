// s = "aab"
// freq = { {'a', 2}, {'b', 1} }
// maxHeap = [ {'a', 1} ]

// res = "aba"

// s = "aaab"
// freq = { {'a', 3}, {'b', 1} }
// maxHeap = [ {'a', 2} ]

// res = "ab"
// when the while loop breaks, we expect only one char left, otherwise return ""

class Solution 
{
    public:
    string reorganizeString(string s) 
    {
        if (s.length() == 0) return "";
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        
        priority_queue<pair<int, char>> maxHeap; // based on freq
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
            if (count2 > 1) maxHeap.push( {count2-1, ch2} );
        }

        if (!maxHeap.empty() && maxHeap.top().first > 1) return "";
        while (!maxHeap.empty()) {
            res += maxHeap.top().second;
            maxHeap.pop();
        }
        return res;
    }
};