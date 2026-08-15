class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;

        stack<int> deck;
        int n = s.length();
        int i=0;
        while (i<n) {
            while (i<n && s[i] == ' ') i++;
            if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;
                while (i<n && s[i] == ' ') i++;

                string currNumStr = "";
                while (i<n && isdigit(s[i])) {
                    currNumStr += s[i];
                    i++;
                }
                if (currNumStr.empty()) return -1;
                int currNum = stoi(currNumStr);
                deck.push(op == '+' ? currNum : -currNum);

            } else if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                i++;
                while (i<n && s[i] == ' ') i++;

                string currNumStr = "";
                while (i<n && isdigit(s[i])) {
                    currNumStr += s[i];
                    i++;
                }
                if (currNumStr.empty()) return -1;
                int currNum = stoi(currNumStr);
                int prevNum = deck.top();
                deck.pop();
                deck.push(op == '*' ? currNum * prevNum : prevNum / currNum);

            } else if (isdigit(s[i])) {
                string currNumStr = "";
                while (i<n && isdigit(s[i])) {
                    currNumStr += s[i];
                    i++;
                }
                int currNum = stoi(currNumStr);
                deck.push(currNum);

            } else {
                i++;
            }
        }

        int res = 0;
        while (!deck.empty()) {
            res += deck.top();
            deck.pop();
        }
        return res;
    }
}; 