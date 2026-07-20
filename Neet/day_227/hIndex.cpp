

// [3,0,6,1,5]
//            h
// [0,1,0,1,0,1]
// total = 1
class Solution 
{
    public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.empty()) return 0;
        int n = citations.size();
        // count[i] = number of papers with exactly i citations
        vector<int> count(n+1, 0);

        for (int c : citations) {
            count[min(c, n)]++;
        }

        int total = 0;
        for (int h=n; h>=0; h--) {
            total += count[h];
            if (total >= h) return h;
        }
        return 0;
    }
};