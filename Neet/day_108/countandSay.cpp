class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string curr = "1";
        for (int i=0; i<n-1; i++) {
            vector<vector<int>> freq = produceFreq(curr);
            curr = createNewInteger(freq);
        }
        return curr;
    }
    private:
    // "223314444411"
    // deck = {2,2}
    // [[2,2], [3,2], [1,1], [4,5], [1, 2]]
    string createNewInteger(vector<vector<int>>& freq) 
    {
        string res = "";
        for (auto& numCount : freq) {
            int num = numCount[0];
            int count = numCount[1];
            res += to_string(count) + to_string(num);
        }
        return res;
    } 
    vector<vector<int>> produceFreq(const string& s)
    {
        stack<pair<char, int>> deck;
        vector<vector<int>> res;

        for (char ch : s) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
            } else if (!deck.empty()) {
                res.push_back( {deck.top().first-'0', deck.top().second} );
                deck.pop();
                deck.push( {ch, 1} );
            } else {
                deck.push( {ch, 1} );
            }
        }
        if (!deck.empty()) {
            res.push_back( {deck.top().first - '0', deck.top().second} );
        }
        return res;
    }
};