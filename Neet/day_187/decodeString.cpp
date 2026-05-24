class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();

        stack<char> deck;

        for (int i=0; i<n; i++) {
            if (s[i] == ']') {
                string currStr = "";
                while (!deck.empty() && deck.top() != '[') {
                    currStr = deck.top();
                    deck.pop();
                }
                deck.pop();

                string scaler = "";
                while (!deck.empty() && isdigit(deck.top())) {
                    scaler = deck.top() + scaler;
                    deck.pop();
                }
                int scalerNum = stoi(scaler);
                string toPush = "";
                for (int i=0; i<scalerNum; i++) {
                    toPush += currStr;
                }

                for (char ch : toPush) {
                    deck.push(ch);
                }

            } else {
                deck.push( s[i] );
            }
        }    

        // consolidate 
        string res = "";
        while (!deck.empty()) {
            res += deck.top() + res;
            deck.top();
        }
        return res;
    }
};