class Solution 
{
    public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;
        int n = s.length();

        for (int i=0; i<n; i++) {
            char sCh = s[i];
            char tCh = t[i];

            if (sTot.count(sCh)) {
                if (sTot[sCh] != tCh) return false;
            } else {
                sTot[sCh] = tCh;
            }

            if (tTos.count(tCh)) {
                if (tTos[tCh] != sCh) return false;
            } else {
                tTos[tCh] = sCh;
            }
        }
        return true;
    }
};