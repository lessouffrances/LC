
// marked [1,1,1,1,1,1]
// nums = [2,3,5,1,3,2]
// score = 1+2+2 = 5

class Solution 
{
    public:
    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();
        // minHeap: { num : idx }
        // pair comparison: the first is num, the second is idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> isMarked(n, 0); 

        // push all pairs onto pq
        for (int i=0; i<n; i++) {
            pq.push( {nums[i], i });
        }

        long long score = 0;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            // if has not been marked yet
            if (isMarked[idx] == 0) {
                isMarked[idx] = 1;
                if (idx-1 >=0) isMarked[idx-1] = 1;
                if (idx+1 < n) isMarked[idx+1] = 1;

                score += num;
            }
        }
        return score;
    }
};