class Solution 
{
    public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>counter(n+1, 0);
        
        vector<int>res(2);
        for (int num : nums) {
            counter[num]++;
            if (counter[num] == 2) res[0] = num;
        }

        auto iter = find_if(counter.begin()+1, counter.end(), [](int val){
            return val == 0;
        });
        // auto iter = find(counter.begin()+1, counter.end(), 0);
        res[1] = iter - counter.begin();
        return res;
    }
};