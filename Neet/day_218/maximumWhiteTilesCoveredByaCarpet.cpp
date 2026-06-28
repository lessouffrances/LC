class Solution 
{
    public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) 
    {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        
        // prefixSum[i] means total while tiles from 0 to i, inclusive
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = tiles[0][1]-tiles[0][0]+1;
        for (int i=1; i<n; i++) {
            int currTileSize = tiles[i][1]-tiles[i][0]+1;
            prefixSum[i] = currTileSize + prefixSum[i-1];
        }

        int maxCovered = 0;
        for (int i=0; i<n; i++) {
            // place carpet at tile[i][0]
            int carpetEnd = tiles[i][0]+carpetLen-1;

            // binary search for the last tile starts <= carpetEnd
            int lo = i, hi = n-1, lastTile = i-1;
            while (lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if (tiles[mid][0] <= carpetEnd) {
                    lastTile = mid;
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }

            if (lastTile < i) continue;

            // while tiles fully covered:
            long long covered = prefixSum[lastTile] - ( i>0 ? prefixSum[i-1] : 0);
            if (tiles[lastTile][1] > carpetEnd) {
                covered -= (tiles[lastTile][1]-carpetEnd);
            }
            maxCovered = max(maxCovered, (int)covered);
        }
        return maxCovered;

    }
};