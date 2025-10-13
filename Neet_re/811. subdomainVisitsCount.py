from collections import defaultdict
class Solution:
    def subdomainVisits(self, cpdomains):
        counter = defaultdict(int)

        for cpdomain in cpdomains:
            visitTimes, completeDomain = cpdomain.split(" ")
            visitTimes = int(visitTimes)
            subDomains = completeDomain.split(".")

            for i in range(len(subDomains)):
                counter[".".join(subDomains[i: ])] += visitTimes
        print(counter)
        
        res = []
        for item in counter.items():
            print(item)
            currString = "" + str(item[1]) + " " + item[0]
            print(currString)
            res.append(currString)
        return res


def main():
    self = Solution
    cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
    Solution.subdomainVisits(self, cpdomains)
main()