class Solution 
{
    public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int> res; // all distinct OR values
        unordered_set<int> current; // OR values ending at current idx
 
        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);
            
            for (int val : current) {
                next.insert(val | num);
            }
            current = next;
            res.insert(current.begin(), current.end());
        }
        return res.size();
    }
};