class Solution 
{
    public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if (s[0] == '1') return false;
        if (s.length() == 0) return true;
        int n = s.length();

        queue<int> q;
        q.push(0);
        int maxReach = 0;

        while (!q.empty()) {
            int currPos = q.front();
            q.pop();

            if (currPos == n-1) return true;
            for (int nextPos = max(maxReach, currPos+minJum); nextPos<=min(currPos+maxJump, n-1); nextPos++) {
                if (s[nextPos] == '1') continue;
                q.push(nextPos);
            }
            maxReach = max(maxReach, currPos+maxJump);
        }
        return false;
    }
};