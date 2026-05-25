class Solution 
{
    public:
    string longestDiverseString(int a, int b, int c) 
    {
        // with the highest count on top
        priority_queue<pair<int, int>> maxHeap;

        if (a > 0) maxHeap.push( {a, 'a'} );
        if (b > 0) maxHeap.push( {b, 'b'} );
        if (c > 0) maxHeap.push( {c, 'c'} );

        string res = "";
        while (!maxHeap.empty()) {
            auto [count1, ch1] = maxHeap.top();
            maxHeap.pop();

            int n = res.length();
            if (n >= 2 && ch1 == res[n-2] && ch1 == res[n-1]) {
                if (maxHeap.empty()) break;
                // the ch1 cannot be used
                auto [count2, ch2] = maxHeap.top();
                maxHeap.pop();

                res += ch2;
                if (count2 > 1) maxHeap.push( {count2-1, ch2} );
                maxHeap.push( {count1, ch1} );
                continue;
            }
            res += ch1;
            if (count1 > 1) maxHeap.push( {count1-1, ch1} );
        }
        return res;
    }
};