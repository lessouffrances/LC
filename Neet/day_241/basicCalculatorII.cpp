class Solution 
{
    public:
    // s = "3+2*2"
    // stack = [3+4]
    int calculate(string s) 
    {
        if (s.empty()) return 0;
        int n = s.length();
        int i=0; 
        stack<int> deck;
        while (i<n) {
            while (i<n && s[i] == ' ') i++;

            if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                i++;
                // want to get the number after the op
                while (i < n && s[i] == ' ') i++;
                
                string currNumStr = "";
                while (i<n && isdigit(s[i])) {
                    currNumStr += s[i];
                    i++;
                }
                if (currNumStr.empty()) return 0; // invalid
                int currNum = stoi(currNumStr);
                int prevNum = deck.top();
                deck.pop();
                deck.push(op == '*' ? prevNum*currNum : prevNum / currNum);

            } else if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;
                // want to get the number after the op
                while (i < n && s[i] == ' ') i++;

                string currNumStr = "";
                while (i<n && isdigit(s[i])) {
                    currNumStr += s[i];
                    i++;
                }
                if (currNumStr.empty()) return 0; // invalid
                int currNum = stoi(currNumStr);
                deck.push(op == '+' ? currNum : -currNum);
                
            } else if (isdigit(s[i])) {
                string currNumStr = "";
                while (i<n && isdigit(s[i])) {
                    currNumStr += s[i];
                    i++;
                }
                if (currNumStr.empty()) return 0; // invalid
                int currNum = stoi(currNumStr);
                deck.push(currNum);

            } else {
                i++;
            }
        }

        // consolidate the stack:
        int res = 0;
        while (!deck.empty()) {
            res += deck.top();
            deck.pop();
        }
        return res;
    }
};