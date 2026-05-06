// T: O(N * M), where N is the n, and M is the average length of strings produced at each step.
// S: O(M)

class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string prev = "1";
        for (int i=1; i<n; i++) {
            prev = countAndSayHelper(prev);
        }
        return prev;
    }

    private:
    string countAndSayHelper(const string& s)
    {
        if (s.length() == 0) return "";
        int n = s.length();
        
        stack<pair<char, int>> deck; // { num, count }
        for (int i=0; i<n; i++) {
            if (!deck.empty() && deck.top().first == s[i]) {
                deck.top().second++;
            } else {
                deck.push( {s[i], 1} );
            }
        }

        // consolidate the stack
        string res = "";
        while (!deck.empty()) {
            auto [num, count] = deck.top();
            deck.pop();
            string foo = to_string(count) + num;
            res = foo + res;
        }
        return res;
    }
};