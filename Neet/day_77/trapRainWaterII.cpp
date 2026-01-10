#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Solution 
{
public:
   int trapRainWater(vector<vector<int>>& heightMap) 
   {
      if (heightMap.empty()) return 0;
      int ROW = heightMap.size();
      int COL = heightMap[0].size();

      priority_queue<tuple<int, int, int>,
                     vector<tuple<int, int, int>>,
                     greater<tuple<int, int, int>>> pq;
      vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

      // add all boundary cells into the heap and mark visited
      for (int r=0; r<ROW; r++) {
         for (int c=0; c<COL; c++) {
            if (r==0 || r==ROW-1 || c==0 || c==COL-1) {
               visited[r][c] = true;
               pq.push( {heightMap[r][c], r, c} ); 
            }
         }
      }

      int water = 0;
      int maxHeight = 0;
      vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};

      while (!pq.empty()) {
         int height = get<0>(pq.top());
         int r = get<1>(pq.top());
         int c = get<2>(pq.top());
         pq.pop();
 
         maxHeight = max(maxHeight, height);
         for (auto& DIR : DIRS) {
            int newR = r + DIR.first;
            int newC = c + DIR.second;
            
            if (newR<0 || newR>= ROW || newC<0 || newC>=COL
               || visited[newR][newC] == true) continue;

            if (heightMap[newR][newC] < maxHeight) {
               water += (maxHeight - heightMap[newR][newC]);
            }
            visited[newR][newC] = true;
            pq.push( {heightMap[newR][newC], newR, newC} );
         }
      }
      return water;
   }
};

int main() {
   Solution solution = Solution();
   vector<vector<int>> map = {{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
   printf("%d\n", solution.trapRainWater(map));
   return 0;
}
