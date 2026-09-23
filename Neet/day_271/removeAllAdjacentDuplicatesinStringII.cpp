

// s = "d e e e d b b c c c b d a a", k = 3
// stack = aa

class Solution 
{
    public:
    string removeDuplicates(string s, int k) 
    {
        if (s.length() == 0) return "";
        int n = s.length();
        stack<pair<char, int>> deck;

        for (int i=0; i<n; i++) {
            if (!deck.empty() && s[i] == deck.top().first) {
                deck.top().second++;
                if (deck.top().second == k) {
                    deck.pop();
                }
            } else {
                deck.push( {s[i], 1} );
            }
        }

        string res = "";
        while (!deck.empty()) {
            auto [ch, count] = deck.top();
            deck.pop();
            res.append(count, ch);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};