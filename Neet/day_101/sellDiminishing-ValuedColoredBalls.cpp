








// inventory = [2,5], orders = 4
// complete = [1,1,2,2,3,4,5]


// inventory = [3,5], orders = 6
// complete = [1,1,2,2,3,3,4,5]



class Solution 
{
    public:
    int maxProfit(vector<int>& inventory, int orders) 
    {
        int totalProfit = 0;
        for (int inven : inventory) {
            totalProfit += (1 + inven) * inven / 2;
        }

        
    }
};