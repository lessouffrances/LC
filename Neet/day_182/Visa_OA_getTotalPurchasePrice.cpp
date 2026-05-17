// Question 1
// You are given a list of item prices at a market. The store has a special discount rule:

// The first item is purchased at full price.
// For every subsequent item, the discount applied is equal to the lowest price among all previously purchased items.
// The final price of an item cannot go below 0.
// Items must be purchased in the given order.

// Your task is to calculate the total cost of buying all items under this pricing rule.
// Example 1
// Suppose there are n = 4 prices: prices = [2, 5, 1, 4].
// Output: 8

// First item costs 2 (no discount applies to the first item)
// Second item costs 5 - 2 = 3 (minimum previous price was 2)
// Third item costs max(1 - min(2, 5), 0) = max(1 - 2, 0) = 0
// Fourth item costs 4 - 1 = 3 (minimum previous price was 1)

// Total cost: 2 + 3 + 0 + 3 = 8
// Example 2
// Suppose n = 4, and prices = [4, 9, 2, 3]
// Output: 10

// First item costs 4 (no discount applies to the first item)
// Second item costs 9 - 4 = 5 (minimum previous price was 4)
// Third item costs max(2 - min(4, 9), 0) = max(2 - 4, 0) = 0

class Solution
{
    public:
    // rule: first price => original
    // all subsequent, price = max( prices[i]-minPrice, 0)

    // [2, 5, 1, 4]
    //     i
    // res = 2+3
    // minP = 2
    // curr = max(5-2, 0) = 3
    int getTotalPurchasePrice(vector<int>& prices)
    {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        int minPrice = prices[0];
        int res = prices[0];
        for (int i=1; i<n; i++) {
            int currPrice = max(prices[i]-minPrice, 0);
            res += currPrice;
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};