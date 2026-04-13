




class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string prev = "1";

        for (int i=1; i<n; i++) {
            prev = countAndSayHelper(prev);
        }
        return prev;
    }
    private:
    string countAndSayHelper(const string& s)
    {
        if (s.length() == 0) return "";
        int n = s.length();
        stack<pair<char, int>> deck;

        for (int i=0; i<n; i++) {
            if (!deck.empty() && s[i] == deck.top().first) {
                deck.top().second++;
            } else {
                deck.push( {s[i], 1} );
            }
        }

        // consolidate the deck
        string res = "";
        while (!deck.empty()) {
            auto [ch, count] = deck.top();
            string foo = to_string(count) + ch;
            res = foo + res;
            deck.pop();
        }

        return res;
    }
};