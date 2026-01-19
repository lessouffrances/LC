class Solution 
{
   public:
   int countSubstrings(string s) 
   {
      int n = s.length();

      int res = 0;
      for (int start=0; start<n; start++) {
         for (int end=n; end>start; end--) {
            string currStr = string(s.begin()+start, s.begin()+end);
            string copyCurrStr = currStr;
            reverse(copyCurrStr.begin(), copyCurrStr.end());
            if (currStr == copyCurrStr) res++;
         }
      }
      return res;
   }
};