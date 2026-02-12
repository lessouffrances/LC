/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

 class Solution 
 {
    public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) 
    {
        // no valid area
        if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1]) return 0;

        // if the sea has no ships
        if (!sea.hasShips(topRight, bottomLeft)) return 0;

        // base case
        if (topRight == bottomLeft) return 1;

        // divide into 4
        int midX = (bottomLeft[0] + topRight[0]) / 2;
        int midY = (bottomLeft[1] + topRight[1]) / 2;

        int count = 0;
        // bottom-left square
        count += countShips(sea, {midX, midY}, bottomLeft);

        // bottom-right square
        count += countShips(sea, {topRight[0], midY}, {midX+1, bottomLeft[1]});

        // top-left square
        count += countShips(sea, {midX, topRight[1]}, {bottomLeft[0], midY+1});

        // top-right square
        count += countShips(sea, topRight, {midX+1, midY+1});

        return count;
    }
};