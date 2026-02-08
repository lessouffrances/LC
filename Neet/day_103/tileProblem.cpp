#include <cstdio>
#include <utility>  
using namespace std;  

class Solution
{
public:
    pair<int, int> convertLinearToTiled(int row, int col, int boxSize)
    {
        int tiledRow =  (col / boxSize) + (row / boxSize) * boxSize;
        int tiledCol = (col % boxSize) + (row % boxSize) * boxSize;

        printf("%d, %d\n", tiledRow, tiledCol);  
        pair<int, int> res;
        res.first = tiledRow;
        res.second = tiledCol;
        return res;
    }
};

int main()
{
    Solution solution;  
    solution.convertLinearToTiled(9, 11, 4);
    solution.convertLinearToTiled(0, 0, 4);
    solution.convertLinearToTiled(0, 4, 4);
    solution.convertLinearToTiled(0, 15, 4);
    solution.convertLinearToTiled(15, 0, 4);
    return 0;
}  