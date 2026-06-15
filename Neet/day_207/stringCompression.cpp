class Solution 
{
    public:
    int compress(vector<char>& chars) 
    {
        stack<pair<char, int>> deck;

        for (char ch : chars) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
            } else {
                deck.push( {ch, 1} );
            }
        }

        vector<pair<char, int>> groups;
        while (!deck.empty()) {
            groups.push_back(deck.top());
            deck.pop();
        }
        reverse(groups.begin(), groups.end());

        int write = 0;
        for (auto& p : groups) {
            char ch = p.first;
            chars[write++] = ch;
            int count = p.second;
            string strCount = to_string(count);
            if (count > 1) {
                for (char c : strCount) {
                    chars[write++] = c;
                }
            } 
        }
        return write;
    }
};