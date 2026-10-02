class Solution 
{
    public:
    int jump(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        int n = nums.size();

        queue<int> q;
        q.push(0);
        int steps = 0;
        int maxReach = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currPos = q.front(); q.pop();
                if (currPos == n-1) return steps;

                for (int nextPos=maxReach; nextPos<=min(n-1, currPos+nums[currPos]); nextPos++) {
                    q.push(nextPos);
                }
                maxReach = max(maxReach, currPos+nums[currPos]);
            }
            steps++;
        }
        return -1;
    }
};