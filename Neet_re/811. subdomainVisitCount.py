from collections import defaultdict
class Solution:
    def subdomainVisits(self, cpdomains):
        counter = defaultdict(int)
        for cpdomain in cpdomains:
            times, domain = cpdomain.split(" ")
            times = int(times)
            subdomains = domain.split('.')
            for i in range(len(subdomains)-1, -1, -1):
                currPortion = subdomains[i: ]
                currPortion = ".".join(currPortion)
                print(currPortion)
                counter[currPortion] += times
        print(counter)
       
        res = []
        for key, value in counter.items():
            print((key, value))
            currString = str(value) + " " + key
            res.append(currString)
        print(res)
        return res




            




def main():
    self = Solution
    # cpdomains = ["9001 discuss.leetcode.com"]
    cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
    Solution.subdomainVisits(self, cpdomains)
main()