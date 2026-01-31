class Solution 
{
    public:
    string removeDuplicates(string s, int k) 
    {
        if (s.length() == 0) return "";
        int n = s.length();

        stack<pair<char, int>> deck;
        for (int i=0; i<n; i++) {
            if (!deck.empty() && deck.top().first == s[i]) {
                deck.top().second++;

                if (deck.top().second == k) {
                    deck.pop();
                }
            } else {
                deck.push( {s[i], 1});
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