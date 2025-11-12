#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <map>

std::set<int> getUniqueDigits(const std::vector<int>& numbers) 
{
  std::set<int> digits;
  for (int num : numbers) {
    std::string numStr = std::to_string(num);
    for (char c : numStr) {
      digits.insert(c-'0');
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


int solution(std::vector<int>& A) 
{
  std::vector<std::set<int>> numberSets;
  for (auto& number : A) {
    numberSets.push_back(getDigits(number));
  }
  // printVectorOfSets(numberSets);
  std::set<int> uniqueDigits =  getUniqueDigits(A);
  
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





