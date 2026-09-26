// " ( ) ) ) ( ( "
// ( (
// count 1+1+1+1
// when encounter close, if deck holds open, pop the open without increment the count 
//                       if deck holds no open, increment the count

// the remaining on the stack are invalid opens, increment the count

class Solution 
{
    public:
    int minAddToMakeValid(string s) 
    {
        // use a stack
        if (s.length() == 0) return 0;
        stack<char> deck;
        int count = 0;

        for (char ch : s) {
            if (ch == ')') {
                if (!deck.empty()) {
                    deck.pop();
                } else {
                    count++;
                }
            } else {
                deck.push(ch);
            }
        }
        
        while (!deck.empty()) {
            deck.pop();
            count++;
        }
        return count;
    }
};