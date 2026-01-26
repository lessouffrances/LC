class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.length() == 0) return "";
        stack<char> deck;
        int i = 0;
        int n = s.length();

        while (i < n) {
            if (s[i] != ']') {
                deck.push(s[i]);
            } else {
                string subStr = "";
                while (!deck.empty() && deck.top() != '[') {
                    subStr = deck.top() + subStr;
                    deck.pop(); 
                }
                
                // must be a moment when the top is [
                deck.pop();
                string scaler = "";
                while (!deck.empty() && deck.top() >= '0' && deck.top() <= '9') {
                    scaler = deck.top() + scaler;
                    deck.pop();
                }

                // let the subStr repeats for {scaler} times
                string portion = "";
                for (int i=0; i<stoi(scaler); i++) {
                    portion += subStr;
                }

                // push each char in the portion onto the stack
                for (char ch : portion) {
                    deck.push(ch);
                }
            }
            i++;
        }

        string res = "";
        while (!deck.empty()) {
            res = deck.top() + res;
            deck.pop();
        }
        return res;
    }
};
