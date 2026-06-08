// i + minJump <= j <= min(i + maxJump, s.length - 1)
// s[j] == '0'

class Solution 
{
    public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if (s[0] == '1' || s.back() == '1') return false;
        int n = s.length();

        queue<int> q;
        q.push(0);
        unordered_set<int> visited; // idxes
        visited.insert(0);
        int maxReach = 0;

        while (!q.empty()) {
            auto currPos = q.front();
            q.pop();

            if (currPos >= n-1) return true;

            // look for nextPos
            for (int nextPos=max(maxReach, currPos+minJump); nextPos<=min(currPos+maxJump, n-1); nextPos++) {
                if (visited.count(nextPos) || s[nextPos] == '1') continue;
                q.push(nextPos);
                visited.insert(nextPos);
            }
            maxReach = max(maxReach, min(currPos+maxJump, n-1));
        }
        return false;
    }
};