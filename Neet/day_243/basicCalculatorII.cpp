class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.empty()) return 0;
        
        int n = s.length();
        int i=0; 
        stack<int> deck;

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
                int currNum = stoi(currNum);
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
                int currNum = stoi(currNum);
                int prevNum = deck.top();
                deck.pop();
                deck.push(op == '*' ? prevNum * currNum : prevNum / currNum);

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