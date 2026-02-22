class Solution 
{
    public:
    int maxPoints(vector<vector<int>>& points) 
    {
        if (points.empty()) return 0;

        int n = points.size();
        if (n <= 2) return n;
        int maxPoints = 0;
        for (int i=0; i<n; i++) {
            map<pair<int, int>, int> slopeCount;
            int dup = 0;
            int currMax = 0;
            
            for (int j=i+1; j<n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    dup++;
                    continue;
                }

                if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                } else {
                    int greatestCommonDivisor = findGCD(abs(dx), abs(dy));
                    dx /= greatestCommonDivisor;
                    dy /= greatestCommonDivisor;

                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                }
                pair<int, int> slope = {dx, dy};
                slopeCount[slope]++; 
                currMax = max(currMax, slopeCount[slope]);
            }
            maxPoints = max(maxPoints, currMax + dup + 1);
        }
        return maxPoints;
    }
    private:
    int findGCD(int a, int b)
    {
        if (b == 0) {
            return a;
        } else {
            return findGCD(b, a % b);
        }
    }
};