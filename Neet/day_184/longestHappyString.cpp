class Solution 
{
    public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int, char>> pq; // default maxHeap
        
        if (a > 0) pq.push( {a, 'a'} );
        if (b > 0) pq.push( {b, 'b'} );
        if (c > 0) pq.push( {c, 'c'} );

        string res = "";

        while (!pq.empty()) {
            auto [count1, ch1] = pq.top();
            pq.pop();

            int n = res.size();
            // if last two chars are the same as the ch1,
            // need to pick the second highest frequent one
            if (n >=2 and res[n-1] == ch1 && res[n-2] == ch1) {
                if (pq.empty()) break;
                auto [count2, ch2] = pq.top();
                pq.pop();
                res += ch2;
                if (count2 > 1) pq.push( {count2-1, ch2} );
                pq.push( {count1, ch1} );
            } else {
                res += ch1;
                if (count1 > 1) pq.push( {count1-1, ch1} );
            }
        }
        return res;
    }
};