




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
    // "1211" => "11 12 21"
    unordered_map<string, string> memo;
    string countAndSayHelper(const string& s)
    {
        if (s.length() == 0) return "";

        if (memo.count(s)) return memo[s];

        stack<pair<int, char>> deck; // { count, char }
        for (char ch : s) {
            if (!deck.empty() && ch == deck.top().second) {
                deck.top().first++;
            } else {
                deck.push( {1, ch} );
            }
        }

        // consolidate the deck and return string
        string res = "";
        while (!deck.empty()) {
            auto foo = to_string(deck.top().first) + deck.top().second;
            res = foo + res;
            deck.pop();
        }

        memo[s] = res;
        return res;
    }
};