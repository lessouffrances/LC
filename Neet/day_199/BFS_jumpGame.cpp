class Solution 
{
    public:
    // nums = [3,2,1,0,4]
    bool canJump(vector<int>& nums) 
    {
        int goal = nums.size()-1;
        queue<int> q; 
        q.push(0); // initially at pos 0
        unordered_set<int> visited;
        visited.insert(0);
        
        while (!q.empty()) {
            auto currPos = q.front();
            q.pop();

            if (currPos >= goal) return true;

            // where is the next Pos I can jump to?
            // cuz nums[currPos] specify the farthest dist 
            // so [0....nums[currPos] ] are all places I can land
            for (int i=0; i<=nums[currPos]; i++) {
                long long nextPos = currPos + i;
                if (visited.count(nextPos)) continue;
                visited.insert(nextPos);
                q.push(nextPos);
            }
        }
        return false;
    }
};