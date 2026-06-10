class Solution 
{
    public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if (s[0] == '1' || s.back() == '1') return false;
        int n = s.length();

        queue<int> q; // store indexes
        q.push(0);

        int maxReach = 0;

        while (!q.empty()) {
            auto currPos = q.front();
            q.pop();

            if (currPos >= n-1) return true;

            for (int nextPos=max(maxReach, currPos+minJump); nextPos<=min(n-1, currPos+maxJump); nextPos++)
            {
                if (s[nextPos] == '1') continue; 
                q.push(nextPos);
            }
            maxReach = max(maxReach, currPos+maxJump);
        }
        return false;
    }
};