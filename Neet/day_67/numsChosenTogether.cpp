#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <map>

class Solution {
    public:
    int numsChosenTogether(std::vector<int>& numbers) 
    {
        std::vector<std::set<int>> numberSets;
        for (auto& number : numbers) {
            numberSets.push_back(getDigits(number));
        }
        // printVectorOfSets(numberSets);
        std::set<int> uniqueDigits =  getUniqueDigits(numbers);
        
        // sharingMap is about { one digit : all numberSets that contains this digit }
        std::map<int, std::vector<std::set<int>>> sharingMap;
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

        auto it = std::max_element(sharingMap.begin(), sharingMap.end(), [](const auto& a, const auto& b) {
            return a.second.size() < b.second.size();
        });

        std::printf("%zu\n", it->second.size());
        return it->second.size();
    }

    private:
    std::set<int> getUniqueDigits(const std::vector<int>& numbers) 
    {
        std::set<int> digits;
        for (int num : numbers) {
            std::string numStr = std::to_string(num);
            for (char c : numStr) {
                digits.insert(c - '0');
            }
        }
        return digits;
    }

    std::set<int> getDigits(const int& number) 
    {
        std::set<int> digits;
        std::string numStr = std::to_string(number);
        
        for (char c : numStr) {
            digits.insert(c - '0');  
        }
        return digits;
    }

    void printVectorOfSets(const std::vector<std::set<int>>& vecOfSets) {
        for (auto& s : vecOfSets) { 
            std::cout << "{ "; 
            for (int x : s) { 
                std::cout << x << " "; 
            } 
            std::cout << "} "; 
        } 
        std::cout << std::endl;
    }

    void printSharingMap(const std::map<int, std::vector<std::set<int>>>& sharingMap) 
    {
        std::printf("{\n");
        for (const auto& [key, vecOfSets] : sharingMap) {
            std::printf(" %d: [", key);

            for (size_t i=0; i<vecOfSets.size(); i++) {
                std::printf("{");
                bool first = true;

                for (int val : vecOfSets[i]) {
                    if (!first) std::printf(", ");
                    std::printf("%d", val);
                    first = false;
                } 
                std::printf("}");
                if (i<vecOfSets.size()-1) std::printf(", "); 
            }
            std::printf("]\n");
        }
        std::printf("}\n");
    }
};

int main() 
{
    Solution solution = Solution();
    std::vector<std::vector<int>> numbers = {
        {52, 25, 11, 52, 34, 55},
        {71, 23, 57, 15}, 
        {11, 33, 55}
    };

    for (auto& num : numbers) {
        solution.numsChosenTogether(num);
    }
}