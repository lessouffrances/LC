



// cards = [3, 4, 2, 3, 4, 7]
//             l,       r


class Solution 
{
    public:
    int minimumCardPickup(vector<int>& cards) 
    {
        if (cards.empty()) return -1;
        int n = cards.size();
        int maxi = *max_element(cards.begin(), cards.end());
        vector<pair<int, int>>windowCounter(maxi+1, {0, 0}); // pair as { count, lastIdx }

        int minInterval = INT_MAX;
        for (int right=0; right<n; right++) {
            windowCounter[cards[right]].first++;

            if (windowCounter[cards[right]].first == 2) {
                int lastIdx = windowCounter[cards[right]].second;
                minInterval = min(minInterval, right-lastIdx+1);
                windowCounter[cards[right]].first = 1; // reset
            }
            windowCounter[cards[right]].second = right;
        }
        return minInterval == INT_MAX ? -1 : minInterval;

    }
};