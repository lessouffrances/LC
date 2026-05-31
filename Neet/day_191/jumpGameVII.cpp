

//              0 1 2 3 4 5 6 7
// s = "        0 1 1 0 1 1 1 0", minJump = 2, maxJump = 3
// prefixSum =  

class Solution 
{
    public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if (s[0] == '1' || s.back() == '1') return false;
        int n = s.length();

        queue<int> q;
        q.push(0);
        int maxReached = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next=max(curr+minJump, maxReached+1); 
            next<=min(curr+maxJump, n-1); next++) {
                if (s[next] == '0') {
                    if (next == n-1) return true;
                    q.push(next);
                }
            }
            maxReached = min(curr+maxJump, n-1);
        }
        return false;
    }
};