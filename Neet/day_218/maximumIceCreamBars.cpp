// costs = [1,3,2,4,1], coins = 7, exp = 4
// counter = [2, 1, 1, 1], lowest = 1
class Solution 
{
    public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int n = costs.size();
        int highestCost = *max_element(costs.begin(), costs.end());
        int lowestCost = *min_element(costs.begin(), costs.end());

        // 2, 5
        // 5-2+1 intervals should be allocated
        vector<int> counter(highestCost-lowestCost+1, 0);
        // fill the counter
        for (int& c : costs) {
            counter[c-lowestCost]++;
        }

        // start to buy from the lowest cost
        int total = 0;
        for (int i=0; i<counter.size(); i++) {
            int currPrice = lowestCost+i;
            int currAmount = counter[i];
            if (coins >= (long long)currPrice*currAmount) {
                coins -= currPrice*currAmount;
                total += currAmount;
                continue;
            } else {
                int canBuy = coins / currPrice;
                coins -= canBuy * currPrice;
                total += canBuy;
                break;
            }
        }
        return total;
    }
};