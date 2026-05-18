# Question 3 — Neural Network Equal Layers
# A neural network has n layers, where the number of neurons in the j-th layer is layer[j]. 
# In each generation, the system adjusts the neurons as follows:

# In odd generations: 1 neuron can be added to at most one layer
# In even generations: 2 neurons can be added to at most one layer
# Find the minimum generation in which all layers can have an equal number of neurons.

# Example
# n = 4
# layer = [1, 1, 2, 4]
# The 6th generation is the minimum in which all layers can have an equal number of neurons.

# Function Description
# Complete the function findMinGeneration with the following parameters:
# int layer[n]: the number of neurons in the layers of the network

# Returns
# long: the minimum number of generations until all layers can have an equal number of neurons

class Solution:
    def findMinGeneration(self, layer) -> int:
        target = max(layer)
        lo = 0
        hi = 2 * target * len(layer)
        while lo < hi:
            mid = (lo+hi) // 2;
            if self.canFinish(mid, layer, target):
                hi = mid
            else:
                lo = mid+1
        return lo

    def canFinish(self, g, layer, target) -> bool:
        # only even iter give +2
        # and we want as many +2 as possible
        add_two_count = g // 2
        add_one_count = g - add_two_count;

        twos_needed, ones_needed = 0, 0

        # record all diff each layer
        for x in layer:
            diff = target-x
            twos_needed += diff // 2
            if diff % 2 != 0:
                ones_needed += 1
        return add_two_count >= twos_needed and add_one_count >= ones_needed

            


       