class Solution 
{
public:
   string minRemoveToMakeValid(string s) 
   {
      stack<int> deck;
      unordered_set<int> toRemove;

      for (int i=0; i<s.size(); i++) {
         if (s[i] == '(') {
            deck.push(i);
         } else if (s[i] == ')') {
            if (!deck.empty()) {
               deck.pop();
            } else {
               toRemove.insert(i);
            }
         } 
      }

      while (!deck.empty()) {
         toRemove.insert(deck.top());
         deck.pop();
      }

      string res;
      for (int i=0; i<s.size(); i++) {
         if (toRemove.find(i) == toRemove.end()) {
            res += s[i];
         }
      }
      return res;
   }
};
