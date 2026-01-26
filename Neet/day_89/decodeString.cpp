

// s = "3[a]2[b3[e]c]"
// "beeecbeeecbeeecbeeecbeeecbeeec


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
                    subStr = deck.top() + subStr; // this seq matters
                    deck.pop();
                }

                // when top is [
                deck.pop();

                string scaler = "";
                while (!deck.empty() && deck.top() >= '0' && deck.top() <= '9') {
                    scaler = deck.top() + scaler;
                    deck.pop();
                }

                // let the subStr repeats for {scaler} times
                string str = "";
                for (int i=0; i<stoi(scaler); i++) {
                    str += subStr;
                }

                // note that we are dealing with the char type
                for (char ch : str) {
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