class Solution 
{
    public:
    string compressedString(string word) 
    {
        if (word.empty()) return "";

        stack<pair<int, char>> deck;
        for (char ch : word) {
            if (!deck.empty() && ch == deck.top().second) {
                deck.top().first++;
            } else {
                deck.push( {1, ch} );
            }
        }

        // consolidate the stack
        string res = "";
        vector<string> parts;
        while (!deck.empty()) {
            auto& p = deck.top();
            deck.pop();
            parts.push_back(processOnePair(p));
        }
            
        for (int i = parts.size()-1; i >= 0; i--) {
            res += parts[i];
        }
        return res;
    }

    private:
    string processOnePair(const pair<int, char>& charToCount) 
    {
        int count = charToCount.first;
        int ch = charToCount.second;
        string res = "";

        int multiples = count / 9;
        int mod = count % 9;

        for (int i=0; i<multiples; i++) {
            res += "9" + string(1, ch);
        }

        if (mod > 0) {
            res += to_string(mod);
            res += ch;
        }

        return res;
    }
};