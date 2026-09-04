class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.length() == 0) return "";

        stack<char> deck;
        for (char ch : s) {
            if (ch == ']') {
                // exit stack
                string currStr = "";
                while (!deck.empty() && deck.top() >= 'a' && deck.top() <= 'z') {
                    currStr = currStr + deck.top();
                    deck.pop();
                }
                deck.pop();

                string currNum = "";
                while (!deck.empty() && isdigit(deck.top())) {
                    currNum = deck.top() + currNum;
                    deck.pop();
                }

                int scaler = stoi(currNum);
                string toPush = "";
                for (int i=0; i<scaler; i++) {
                    toPush += currStr;
                }
                for (char ch : toPush) {
                    deck.push(ch);
                }
            } else {
                deck.push(ch);
            }
        }

        // consolidate the deck
        string res = "";
        while (!deck.empty()) {
            res = deck.top() + res;
            deck.pop();
        }
        return res;
    }
};