class Solution 
{
public:
   int largestIsland(vector<vector<int>>& grid) 
   {
      ROW = grid.size();
      COL = grid[0].size();
      unordered_map<int, int> islandSize; // islandID -> size
      int islandId = 2;
      for (int r=0; r<ROW; r++) {
         for (int c=0; c<COL; c++) {
            if (grid[r][c] == 1) {
               int size = dfs(grid, r, c, islandId);
               islandSize[islandId] = size;
               islandId ++;
            }
         }
      }
      int maxSize = 0;
      for (auto& [id, size] : islandSize) {
         maxSize = max(maxSize, size);
      }
      for (int r=0; r<ROW; r++) {
         for (int c=0; c<COL; c++) {
            if (grid[r][c] == 0) {
               // find adjacent islands
               set<int> adjIslands = getAdjIslands(grid, r, c);
               int totalSize = 1;
               for (int id : adjIslands) {
                  totalSize += islandSize[id];
               }
               maxSize = max(maxSize, totalSize);
            }
         }
      }
      return maxSize;
   }
private:
   int ROW, COL;
   vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
   int dfs(vector<vector<int>>& grid, int r, int c, int islandId)
   {
      if (r<0 || r>=ROW || c<0 || c>=COL || grid[r][c] != 1) return 0;
      grid[r][c] = islandId;
      int size = 1;
      for (auto& DIR : DIRS) {
         int newR = r + DIR.first;
         int newC = c + DIR.second;
         size += dfs(grid, newR, newC, islandId);
      }
      return size;
   }

   set<int> getAdjacentIslands(vector<vector<int>>& grid, 
                               int r, int c) {
      set<int> islands;
      for (auto& DIR : DIRS) {
         int newR = r + DIR.first;
         int newC = c + DIR.second;
         if (newR>=0 && newR<ROW && newC>=0 && newC<COL
             && grid[newR][newC] > 1) {
            islands.insert( grid[newR][newC] );
         }
      }
      return islands;
   }
};
