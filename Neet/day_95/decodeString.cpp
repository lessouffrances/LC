









//                    i
// s = "2[abc]3[cd]ef"
// deck = abcabccdcdcdef


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
                // pop all the number until [ is met
                string currStr = "";
                while (!deck.empty() && deck.top() != '[') {
                    currStr = deck.top() + currStr;
                    deck.pop();
                }
                // pop [
                deck.pop();

                // get the entire number before [
                string currNumStr = "";
                while (!deck.empty() && deck.top() >= '0' && deck.top() <= '9') {
                    currNumStr = deck.top() + currNumStr;
                    deck.pop();
                }
                int currNum = stoi(currNumStr);

                // repeat the currStr for currNum times
                string pushStr = "";
                for (int i=0; i<currNum; i++) {
                    pushStr += currStr;
                }
                for (char ch : pushStr) {
                    deck.push(ch);
                }
                
            } else {
                deck.push(s[i]);
            }
        }

        // get the res from deck
        string res = "";
        while (!deck.empty()) {
            res = deck.top() + res;
            deck.pop();
        }

        return res;
    }
};