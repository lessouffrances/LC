class Solution 
{
    public:
    string removeDuplicates(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();
        stack<pair<char, int>> deck;

        for (int i=0; i<n; i++) {
            if (!deck.empty() && deck.top().first == s[i]) {
                deck.top().second++;
                if (deck.top().second == 2) {
                    deck.pop();
                }
            } else {
                deck.push( {s[i], 1} );
            }
        }

        string res = "";
        while (!deck.empty()) {
            res = deck.top().first + res;
            deck.pop();
        }

        return res;
    }
};