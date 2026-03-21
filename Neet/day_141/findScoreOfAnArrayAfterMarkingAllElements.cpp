

// Time: O(N logN)
// Space: O(N)
class Solution 
{
    public:
    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();

        // stores { num, idx }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> isMarked(n, 0);

        // push all {num, idx} pair onto the pq
        for (int i=0; i<n; i++) {
            pq.push( {nums[i], i} );
        }

        long long score = 0;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            if (isMarked[idx] == 0) {
                if (idx-1 >= 0) isMarked[idx-1] = 1;
                if (idx+1 < n) isMarked[idx+1] = 1;
                score += num;
            }
        }
        return score;
    }
};