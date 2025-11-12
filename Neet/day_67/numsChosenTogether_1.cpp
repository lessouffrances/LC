#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
    int numsChosenTogether(vector<int>& numbers) 
    {
        vector<set<int>> numberSets;
        for (auto& number : numbers) {
            numberSets.push_back(getDigits(number));
        }
        // printVectorOfSets(numberSets);
        set<int> uniqueDigits =  getUniqueDigits(numbers);
        
        // sharingMap is about { one digit : all numberSets that contains this digit }
        map<int, vector<set<int>>> sharingMap;
        for (auto uniqueDigit : uniqueDigits) {
            for (size_t i=0; i<numberSets.size(); i++) {
                if (numberSets[i].find(uniqueDigit) != numberSets[i].end()) {
                    sharingMap[uniqueDigit].push_back(numberSets[i]);
                }
            }
        }

        // printSharingMap(sharingMap);
        if (sharingMap.empty()) {
            return 0;
        }

        auto it = max_element(sharingMap.begin(), sharingMap.end(), [](const auto& a, const auto& b) {
            return a.second.size() < b.second.size();
        });

        printf("%zu\n", it->second.size());
        return it->second.size();
    }

    private:
    set<int> getUniqueDigits(const vector<int>& numbers) 
    {
        set<int> digits;
        for (int num : numbers) {
            string numStr = to_string(num);
            for (char c : numStr) {
                digits.insert(c - '0');
            }
        }
        return digits;
    }

    set<int> getDigits(const int& number) 
    {
        set<int> digits;
        string numStr = to_string(number);
        
        for (char c : numStr) {
            digits.insert(c - '0');  
        }
        return digits;
    }

    void printVectorOfSets(const vector<set<int>>& vecOfSets) {
        for (auto& s : vecOfSets) { 
            cout << "{ "; 
            for (int x : s) { 
                std::cout << x << " "; 
            } 
            cout << "} "; 
        } 
        cout << endl;
    }

    void printSharingMap(const map<int, vector<set<int>>>& sharingMap) 
    {
        printf("{\n");
        for (const auto& [key, vecOfSets] : sharingMap) {
            printf(" %d: [", key);

            for (size_t i=0; i<vecOfSets.size(); i++) {
                printf("{");
                bool first = true;

                for (int val : vecOfSets[i]) {
                    if (!first) printf(", ");
                    printf("%d", val);
                    first = false;
                } 
                printf("}");
                if (i<vecOfSets.size()-1) printf(", "); 
            }
            printf("]\n");
        }
        printf("}\n");
    }
};

int main() 
{
    Solution solution = Solution();
    vector<vector<int>> numbers = {
        {52, 25, 11, 52, 34, 55},
        {71, 23, 57, 15}, 
        {11, 33, 55},
        {90, 90, 90},
        {11, 33, 55}
    };

    for (auto& num : numbers) {
        solution.numsChosenTogether(num);
    }
}