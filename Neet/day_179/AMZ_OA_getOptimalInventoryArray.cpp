// Problem Statement: Optimal Inventory
// Context:
// The manager of an Amazon warehouse wants to create an optimal inventory, where all occurrences of each quality value are contiguous in the array.
// To convert the inventory, the manager can perform the following operation any number of times:

// Choose two quality values x and y.
// Replace every product with quality x to have quality y instead.
// This costs num_replacements units of money, where num_replacements is the number of products with quality x at the time of the operation.

// Find the minimum amount of money to convert the inventory into an optimal inventory.
// Note: Quality values can be negative.

// Example:
// n = 7, quality = [7, 7, 5, 7, 3, 5, 3]
// Distinct values and their counts: 7→3, 5→2, 3→2
// One optimal conversion:

// Replace all 5s → 7: costs 2
// Replace all 3s → 7: costs 2
// Total spent: 4

// Function Description:
// Complete the function getMinAmount with the following parameter:

// int quality[n]: the quality of products

// Returns: int — the minimum amount of money spent to make all quality values contiguous.

// Simplify as:
// Optimal Inventory
// Given an integer array quality, you may repeatedly choose two values x and y and replace all occurrences of x with y, 
// at a cost equal to the count of x at the time. 
// Return the minimum total cost to make all occurrences of each value contiguous.
// Example:
// quality = [7,7,5,7,3,5,3]
// Replace 5→7 (cost 2), Replace 3→7 (cost 2)
// Output: 4

class Solution {
    public:
    int getMinAmount(vector<int>& quality) {
       
    }
};