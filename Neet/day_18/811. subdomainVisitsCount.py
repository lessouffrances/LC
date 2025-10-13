from collections import defaultdict
class Solution:
    def subdomainVisits(self, cpdomains):
        counter = defaultdict(int)

        for cpdomain in cpdomains:
            visitTimes, completeDomain = cpdomain.split(" ")
            visitTimes = int(visitTimes)
            # print((visitTimes, completeDomain))
            subDomains = completeDomain.split(".")
            # print(subDomains)

            
            for i in range(len(subDomains)):
                print(subDomains[i:])

                counter[".".join(subDomains[i:])] += visitTimes
        print(counter)
        res = []
        for item in counter.items():
            print(item)
            currString = "" + str(item[1]) + " " + item[0]
            print(currString)
            res.append(currString)
        print(res)
        return res

                

        
        

def main():
    self = Solution
    # cpdomains = ["9001 discuss.leetcode.com"]
    # output = ["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]

    cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
    # output = ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
    Solution.subdomainVisits(self, cpdomains)
main()