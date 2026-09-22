
// s = "d e e e d b b c c c b d a a", k = 3
// stack = [aa]
// when the next char is about to make a triplet with the tops on stack
// delete
// so there should be {char, count} store in stack about consecutive chars

class Solution 
{
    public:
    // monotonicity 
    string removeDuplicates(string s, int k) 
    {
        int n = s.length();
        stack<pair<char, int>> deck;

        for (int i=0; i<n; i++) {
            if (!deck.empty() && s[i] == deck.top().first) {
                deck.top().second++;
                if (deck.top().second == k) deck.pop();
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