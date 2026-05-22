class Solution 
{
    public:
    string makeFancyString(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();

        string res = "";
        stack<pair<char, int>> deck;

        for (int i=0; i<n; i++) {
            if (!deck.empty() and s[i] == deck.top().first) {
                deck.top().second++;
                if (deck.top().second < 3) {
                    res += deck.top().first;
                }
            } else {
                if (!deck.empty()) deck.pop();
                deck.push( {s[i], 1} );
                res += s[i];
            }
        }
        return res;
    }
};