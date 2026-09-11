class Solution 
{
    public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq; // map is sorted in asc by key
        for (int& num : hand) freq[num]++;

        while (!freq.empty()) {
            int currCard = freq.begin()->first;
            // simulate the process
            for (int i=0; i<groupSize; i++) {
                if (freq[currCard+i] == 0) return false;
                freq[currCard+i]--;
                if (freq[currCard+i] == 0) {
                    freq.erase(currCard+i);
                }
            }
        }
        return true;
    }
};