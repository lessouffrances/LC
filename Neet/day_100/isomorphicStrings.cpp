










class Solution 
{
    public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.length() != t.length()) return false;
        int n = s.length();

        unordered_map<char, char> mapS; // s -> t
        unordered_map<char, char> mapT; // t -> s

        for (int i=0; i<n; i++) {
            char charS = s[i];
            char charT = t[i];

            // check map s -> t
            if (mapS.count(charS)) {
                if (mapS[charS] != charT) {
                    return false;
                } 
            } else {
                mapS[charS] = charT;
            }
            // check map t -> s
            if (mapT.count(charT)) {
                if (mapT[charT] != charS) {
                    return false;
                } 
            } else {
                mapT[charT] = charS;
            }
        }
        
        return true;
    }
};