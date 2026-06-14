class Solution 
{
    public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        // can only jump to s[j],
        // where i + minJump <= j <= min(i + maxJump, s.length - 1), and
        // s[j] == '0'

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

            for (int nextPos=max(maxReach, currPos+minJump); nextPos<=min(currPos+maxJump, n-1); nextPos++) {
                if (s[nextPos] == '1') continue;
                q.push(nextPos);
            }
            maxReach = max(maxReach, currPos+maxJump);
        }
        return false;
    }
};