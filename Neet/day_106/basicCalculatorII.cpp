class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        stack<int> deck;
        int i = 0;
        while (i<n) {
            // skip leading space
            while (i<n && s[i] == ' ') {
                i++;
            }

            if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                i++;

                // skip space after op
                while (i<n && s[i] == ' ') {
                    i++;
                }

                // get the entire number after op
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);
                int prevNum = deck.top();
                deck.pop();
                deck.push(op == '*' ? prevNum * currNum : prevNum / currNum);

            } else if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;

                // skip space
                while (i<n && s[i] == ' ') {
                    i++;
                }

                // get the entire number after op
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);
                deck.push(op == '+' ? currNum : -currNum);

            } else if (isdigit(s[i])){
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);
                deck.push(currNum);

            } else {
                i++;
            }
        }

        // evalute the deck
        int ans = 0;
        while (!deck.empty()) {
            ans += deck.top();
            deck.pop();
        }
        return ans;
    }
};