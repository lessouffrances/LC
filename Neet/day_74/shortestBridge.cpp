class Solution 
{
public:
   int shortestBridge(vector<vector<int>>& grid) 
   {
      ROW = grid.size();
      COL = grid[0].size();
      queue<pair<int, int>> q;
      
      // call dfs to mark the first island
      bool found = false; 
      for (int r=0; r<ROW; r++) {
         for (int c=0; c<COL; c++) {
            if (grid[r][c] == 1) {
              dfs(r, c, grid, q);
              found = true;
              break;
            }
         }
         if (found) break;
      }

      int distance = 0;
      while (!q.empty()) {
         int size = q.size();
         for (int i=0; i<size; i++) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& DIR : DIRS) {
               int newR = r + DIR.first;
               int newC = c + DIR.second;
               if (newR<0 || newR>=ROW || newC<0 || newC>=COL
                   || grid[newR][newC] == 2) continue;

               if (grid[newR][newC] == 1) return distance;
               grid[newR][newC] == 2; // mark as visited
               q.push( {newR, newC} ); 
            }
         }
         distance++;
      }
      return -1;
   }

private:
   vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
   int ROW, COL;
   void dfs(int row, int col, vector<vector<int>>& grid, 
            queue<pair<int, int>>& q) {
      // mark and push
      grid[row][col] = 2;
      q.push( {row, col} );

      for (auto& DIR : DIRS) {
         int newR = row + DIR.first;
         int newC = col + DIR.second;

         if (newR<0 || newR>=ROW || newC<0 || newC>=COL
             || grid[newR][newC] != 1) continue;

         dfs(newR, newC, grid, q);
      }
   }
};
