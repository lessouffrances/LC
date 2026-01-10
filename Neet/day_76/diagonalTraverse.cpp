class Solution 
{
public:
   int ROW, COL;
   vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
   {
      if (mat.empty()) return {};
      ROW = mat.size();
      COL = mat[0].size();
      
      // iterate through the left col and bottom row
      vector<vector<int>> collection; 
      for (int r=0; r<ROW; r++) {
         vector<int> diagonalInit = {};
         vector<int> diagonal = linkDiagonal(r, 0, diagonalInit, mat);
         collection.push_back(diagonal);
      }
      for (int c=1; c<COL; c++) {
         vector<int> diagonalInit = {};
         vector<int> diagonal = linkDiagonal(ROW-1, c, diagonalInit, mat);
         collection.push_back(diagonal);
      }
      vector<int> res;
      for (int i=0; i<collection.size(); i++) {
         vector<int> collec = collection[i];
         if (i % 2 != 0) {
            res.insert(res.end(), collec.rbegin(), collec.rend());
         } else {
            res.insert(res.end(), collec.begin(), collec.end());
         }
      }
      return res; 
   }
private:
   // this function return a line of diagonal numbers in the mat
   // dfs
   vector<int> linkDiagonal(int row, int col, vector<int>& diagonal,
                            vector<vector<int>>& mat)
   {
      diagonal.push_back(mat[row][col]);

      int newR = row-1;
      int newC = col+1;
      if (newR<0 || newR >= ROW || newC<0 || newC >= COL) {
         return diagonal;
      } else {
         return linkDiagonal(newR, newC, diagonal, mat);
      }
   }
};
