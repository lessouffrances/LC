


// s = "d e e e d b b c c c b d a a", k = 3
// {d,1} 

class Solution 
{
    public:
    string removeDuplicates(string s, int k) 
    {
        if (s.length() == 0) return "";

        stack<pair<char, int>> deck;
        for (char ch : s) {
            if (!deck.empty() && deck.top().first == ch) {
                deck.top().second++;
                if (deck.top().second == k) {
                    deck.pop();
                }
            } else {
                deck.push({ch, 1});
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