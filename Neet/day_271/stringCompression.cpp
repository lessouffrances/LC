

class Solution 
{
    public:
    int compress(vector<char>& chars) 
    {
        if (chars.empty()) return 0;

        stack<pair<char, int>> deck;
        for (char ch : chars) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
            } else {
                deck.push( {ch, 1} );
            }
        }

        vector<pair<char,int>> groups;
        while (!deck.empty()) {
            groups.push_back(deck.top());
            deck.pop();
        }
        reverse(groups.begin(), groups.end());

        int write = 0;
        for (auto& [ch, count] : groups) {
            chars[write] = ch;
            write++;

            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[write] = c;
                    write++;
                }
            }
        }
        return write;
    }
};