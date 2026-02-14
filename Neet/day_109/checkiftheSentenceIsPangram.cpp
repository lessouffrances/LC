class Solution 
{
    public:
    bool checkIfPangram(string sentence) 
    {
        if (sentence.length() < 26) return false;

        vector<int>metric(26, 0);
        for (char ch : sentence) {
            metric[ch-'a']++;
        }
        return all_of(metric.begin(), metric.end(), [](int& count){
            return count > 0;
        });
    }
};