class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string next = "1";
        while (n > 1) {
            next = countAndSayHelper(next);
            n--;
        }
        return next;
    }
    
    private:
    string countAndSayHelper(const string& s)
    {
        if (s.length() == 0) return "";

        stack<pair<char, int>> deck;
        for (int i=0; i<s.length(); i++) {
            if (!deck.empty() && deck.top().first == s[i]) {
                deck.top().second++;
            } else {
                deck.push( {s[i], 1} );
            }
        }

        string res = "";
        while (!deck.empty()) {
            auto [ch, count] = deck.top();
            deck.pop();
            res = to_string(count)+ch+res;
        }
        return res;
    }
};