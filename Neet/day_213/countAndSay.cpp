class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string next = "1";
        while (n>1) {
            next = countAndSayHelper(next);
            n--;
        }
        return next;
    }

    private:
    string countAndSayHelper(string s)
    {
        if (s.length() == 0) return "";

        stack<pair<char, int>> deck;
        for (char ch : s) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
            } else {
                deck.push( {ch, 1} );
            }
        } 

        string res = "";
        while (!deck.empty()) {
            auto [ch, count] = deck.top();
            res = to_string(count) + ch + res;
            deck.pop();
        }
        return res;
    }
}; 