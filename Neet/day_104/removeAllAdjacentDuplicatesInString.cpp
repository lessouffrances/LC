class Solution 
{
    public:
    string removeDuplicates(string s) 
    {
        if (s.length() == 0) return "";

        stack<pair<char, int>> deck;
        for (char ch : s) {
            if (!deck.empty() && deck.top().first == ch) {
                deck.top().second++;
                if (deck.top().second == 2) {
                    deck.pop();
                }
            } else {
                deck.push( {ch, 1} );
            }
        } 

        string ans = "";
        while (!deck.empty()) {
            auto& [ch, count] = deck.top();
            deck.pop();
            ans.append(count, ch);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};