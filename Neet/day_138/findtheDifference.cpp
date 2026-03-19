

// Time: O(N logN)
// Space: O(N)
class Solution 
{
    public:
    char findTheDifference(string s, string t) 
    {
        multiset<char> sSet(s.begin(), s.end());
        multiset<char> tSet(t.begin(), t.end());

        for (char ch : sSet) {
            auto it = tSet.find(ch);
            tSet.erase(it);
        }
        return *tSet.begin();
    }
};