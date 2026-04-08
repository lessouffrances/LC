class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string prev = "1";
        for (int i=0; i<n-1; i++) {
            prev = countAndSayHelper(prev);
        }
        return prev;
    }
    private:
    string countAndSayHelper(const string& s)
    {
        if (s.length() == 0) return "";
        stack<pair<char, int>> deck;

        string res = "";
        for (char ch : s) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
                continue;
            }
            deck.push( {ch, 1} );
        }

        while (!deck.empty()) {
            auto [ch, count] = deck.top();
            deck.pop();
            res = to_string(count) + ch + res;
        }
        return res;
    }
};