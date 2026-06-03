class Solution 
{
    public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        // leftright compare 0,2
        // abovebelow compare 1,3
        return !(rec1[2] <= rec2[0] ||  // rec1 is left of rec2
                 rec2[2] <= rec1[0] ||  // rec2 is left of rec1
                 rec1[3] <= rec2[1] ||  // rec1 is below rec2
                 rec2[3] <= rec1[1]);   // rec2 is below rec1
    }
};