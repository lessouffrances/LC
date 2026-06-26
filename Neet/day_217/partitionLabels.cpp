


// "a b a b c bacadefegdehijhklij"



class Solution 
{
    public:
    vector<int> partitionLabels(string s) 
    {
        // record the last occurrence of each char
        int n = s.length();
        unordered_map<int, int> lastOccur;
        for (int i=0; i<n; i++) {
            lastOccur[s[i]] = i;
        }

        vector<int> res;
        int left = 0, right = 0;
        for (int i=0; i<n; i++) {
            right = max(right, lastOccur[s[i]]);
            if (i == right) {
                res.push_back(right-left+1);
                left = i+1;
            }
        }
        return res;
    }
};