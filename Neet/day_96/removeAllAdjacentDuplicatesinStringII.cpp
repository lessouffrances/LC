class Solution 
{
    public:
    string removeDuplicates(string s, int k) 
    {
        if (s.length() == 0) return "";

        stack<pair<char, int>> deck;

        for (char ch : s) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
                if (deck.top().second == k) {
                    deck.pop();
                }
            } else {
                deck.push( {ch, 1} );
            }
        }

        string res = "";
        while (!deck.empty()) {
            auto [ch, count] = deck.top();
            res.append(count, ch);
            deck.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};