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
        // { count, releaseTime, ch }, for people who don't have hands on C++, 
        // specify format
        priority_queue<tuple<int, int, char>> maxHeap;
        // push all pairs onto pq
        for (auto& [ch, count] : freqS) {
            maxHeap.push( {count, 0, ch} );
        }

        // q is to hold the items for __ seconds, 
        // for its FIFO nature
        queue<tuple<int, int, char>> q;
        int currTime = 0;
        string res = "";
        while (!maxHeap.empty() || !q.empty()) {
            // see if there are any items can be released from q
            // when the currTime exceeds the releaseTime for that item
            // the iteam can be released
            while (!q.empty() && currTime >= get<1>(q.front())) {
                maxHeap.push( q.front() );
                q.pop();
            }

            if (maxHeap.empty()) break;

            auto [count, releaseTime, ch] = maxHeap.top();
            maxHeap.pop();
            res += ch;

            if (count > 1) {
                q.push( {count-1, currTime+2, ch} );
            }
            currTime++;
        }

        if (!maxHeap.empty() || !q.empty()) return "";
        return res;
    }
};