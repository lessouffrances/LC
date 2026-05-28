class Solution 
{
    public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if (s[0] == '1' || s.back() == '1') return false;
        int n = s.length();

        vector<bool> reachable(n, false);
        reachable[0] = true;

        for (int i=1; i<n; i++) {
            if (s[i] == '1') continue;
            for (int j=max(0, i-maxJump); j<=i-minJump; j++) {
                if (reachable[j]) {
                    reachable[i] = true;
                    break;
                }
            }
        }
        return reachable[n-1];
    }
};