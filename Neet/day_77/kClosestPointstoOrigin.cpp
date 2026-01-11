#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
using namespace std;

#include <vector>
#include <cmath>
#include <queue>

class Solution {
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        if (points.empty()) return {};

        priority_queue<pair<int, vector<int>>, 
                       vector<pair<int, vector<int>>>,
                       greater<pair<int, vector<int>>>> pq;

        // push all points onto the minheap
        for (auto& pt : points) {
            int dist = computeDist(pt);
            pq.push( {dist, pt} );
        }
        
        vector<vector<int>> res;
        while (!pq.empty() && k>0) {
            auto pt = pq.top().second;
            res.push_back(pt);
            pq.pop();
            k--;
        }
        return res;

    }
    private:
    int computeDist(vector<int>& point)
    {
        int x = point[0];
        int y = point[1];

        return x * x + y * y;
    }
};

int main() {
    Solution solu = Solution();

    vector<vector<int>> test_1 = { {-5,4},{-6,-5},{4,6}};
    int k = 2;

    solu.kClosest(test_1, k);

}