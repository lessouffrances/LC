// Question 3 — Neural Network Equal Layers
// A neural network has n layers, where the number of neurons in the j<sup>th</sup> layer is layer[j]. In each generation, the system adjusts the neurons as follows:

// In odd generations: 1 neuron can be added to at most one layer
// In even generations: 2 neurons can be added to at most one layer
// Find the minimum generation in which all layers can have an equal number of neurons.

// Example
// n = 4
// layer = [1, 1, 2, 4]
// The 6th generation is the minimum in which all layers can have an equal number of neurons.

// Function Description
// Complete the function findMinGeneration with the following parameters:
// int layer[n]: the number of neurons in the layers of the network

// Returns
// long: the minimum number of generations until all layers can have an equal number of neurons

class Solution 
{
    public:
    long findMinGeneration(vector<int>& layer) 
    {
        int target = *max_element(layer.begin(), layer.end());
        long long lo = 0, hi = 2LL * target * layer.size();
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canFinish(mid, layer, target)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
    private:
    bool canFinish(long long g, vector<int>& layer, int target) 
    {
        long long addTwoCount = g / 2;
        long long addOneCount = g - g / 2;

        long long twosNeeded = 0, onesNeeded = 0;
        for (int x : layer) {
            int diff = target - x;
            twosNeeded += diff / 2;
            if (diff % 2 == 1) onesNeeded++;
        }
        return addTwoCount >= twosNeeded && addOneCount >= onesNeeded;
    }

};