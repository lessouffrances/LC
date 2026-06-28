class Solution 
{
    public:
    int maxDistance(vector<int>& position, int m) 
    {
        int right = *max_element(position.begin(), position.end())-*min_element(position.begin(), position.end());
        int left = 1;
        sort(position.begin(), position.end());

        // the binary search will be in range [ left, right ]
        while (left < right) {
            int mid = left + (right-left+1)/2;
            if (canPlaceAllBalls(position, mid, m)) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        return left;
    }

    private:
    bool canPlaceAllBalls(vector<int>& position, int dist, int m)
    {
        m--;
        int lastPlacement = position[0];
        for (int i=1; i<position.size(); i++) {
            if (position[i]-lastPlacement >= dist) {
                lastPlacement = position[i];
                m--;
            } else {
                continue;
            }
        }
        return m <= 0;
        
    }
};
