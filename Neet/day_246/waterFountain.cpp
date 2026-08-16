/* 
Imagine fountain pumping water only if they are above surface.
Your job is to compute which place is safe to stand on and which is not.
You are given an array of N integers and another array of K integers from range [0, N-1].

The first array describe the terrian, these are heights of the points.
The second array contains positions of fountains that pump water on the terrian.

Fountains are sorted in ascending order by their position.
Compute a bit mask of length N (an array of integers or booleans)
that will encode 1 (or true) on each position.

Let's say you have:
          0,1,2,3,4,5
Terrain: [2,1,3,2,1,1]
Fountain: [0,3]

Here's how it works: 
Fountain 0: This fountain is at height 2. It can water position 1 to its right (because 1 < 2) 
only since there's nothing to its left.
Fountain 3: This fountain is at height 2. It can water positions 4 and 5.

Therefore, the positions that get watered are 1, 4, and 5. 
The output would be a bitmask like [0,1,0,0,1,1].

Note: Water will not go past an area of higher terrain.
*/

class Solution
{
    vector<int> getWateredPositions(vector<int>& terrain, vector<int>& fountains)
    {
        if (fountains.empty()) return vector<int>(terrain.size(), 0);
        if (terrain.empty()) return {};

        int m = terrain.size();
        int n = fountains.size();
        vector<int> res(m, 0); 

        // loop thru the queried positions
        for (int i=0; i<n; i++) {
            int pos = fountains[i];
            int height = terrain[pos];

            // the positions to be flowed started 
            int j = pos;
            while (j+1 < m && terrain[j+1] <= height) {
                res[j+1] = 1;
                j++;
            }

            j = pos;
            while (j-1 >= 0 && terrain[j-1] <= height) {
                res[j-1] = 1;
                j--;
            }
        }
        return res;
    }
}
