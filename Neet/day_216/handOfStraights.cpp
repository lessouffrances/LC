class Solution 
{
    public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> freq;
        for (int card : hand) freq[card]++;
        
        while (!freq.empty()) {
            int currCard = freq.begin()->first;
            for (int i=0; i<groupSize; i++) {
                if (freq[currCard+i] == 0) return false;
                freq[currCard+i]--;
                if (freq[currCard+i] < 1) {
                    freq.erase(currCard+i);
                }
            }
        }
        return true;
    }
};