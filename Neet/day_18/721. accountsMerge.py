from collections import defaultdict
class Solution:
    def accountsMerge(self, accounts):
        hashMap = defaultdict(set)
        print(hashMap)
        anotherRes = []
        res = []

        for account in accounts:
            samePerson = False
            if account[0] in hashMap:
                for i in range(1, len(account)):
                    if account[i] in hashMap[account[0]]:
                        samePerson = True
                        break
                if samePerson:
                    for i in range(1, len(account)):
                        hashMap[account[0]].add(account[i])
                else:
                    anotherRes.append(account)
            else:
                hashMap[account[0]] = set()
                for i in range(1, len(account)):
                    hashMap[account[0]].add(account[i])

        print(hashMap)
        print(anotherRes)
        
        for key in hashMap:
            currAccount = []
            currAccount.append(key)
            for email in hashMap[key]:
                currAccount.append(email)
            print(currAccount)
            res.append(currAccount)
        
        res.extend(anotherRes)
        print("res: ", res)

        for i in range(len(res)):
            emailSet = set()
            for j in range(1, len(res[i])):
                emailSet.add(res[i][j])
            print("emailSet: ", emailSet)
            emailPortion = list(emailSet)
            print("emailPortion: ", emailPortion)
            sortedEmailPortion = sorted(emailPortion)
            print(sortedEmailPortion)
            res[i][1: ] = sortedEmailPortion
        print(res)
        return res


def main():
    self = Solution
    accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
                ["John","johnsmith@mail.com","john00@mail.com"],
                ["Mary","mary@mail.com"],
                ["John","johnnybravo@mail.com"]]
    
    # output = [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
    #  ["Mary","mary@mail.com"],
    #  ["John","johnnybravo@mail.com"]]

    # accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],
    #             ["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
    #             ["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
    #             ["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
    #             ["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
    
    # output = [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
    #           ["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
    #           ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
    #           ["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
    #           ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

    accounts = [["Kevin","Kevin1@m.co","Kevin5@m.co","Kevin2@m.co"],
                ["Bob","Bob3@m.co","Bob1@m.co","Bob2@m.co"],
                ["Lily","Lily3@m.co","Lily2@m.co","Lily0@m.co"],
                ["Gabe","Gabe2@m.co","Gabe0@m.co","Gabe2@m.co"],
                ["Kevin","Kevin4@m.co","Kevin3@m.co","Kevin3@m.co"]]
    
    # output = [["Lily","Lily0@m.co","Lily2@m.co","Lily3@m.co"],
    #           ["Gabe","Gabe0@m.co","Gabe2@m.co"],
    #           ["Kevin","Kevin1@m.co","Kevin2@m.co","Kevin5@m.co"],
    #           ["Kevin","Kevin3@m.co","Kevin4@m.co"],
    #           ["Bob","Bob1@m.co","Bob2@m.co","Bob3@m.co"]]

    accounts = [["David","David0@m.co","David1@m.co"],
                ["David","David3@m.co","David4@m.co"],
                ["David","David4@m.co","David5@m.co"],
                ["David","David2@m.co","David3@m.co"],
                ["David","David1@m.co","David2@m.co"]]
    
    output = [["David","David0@m.co","David1@m.co","David2@m.co","David3@m.co","David4@m.co","David5@m.co"]]
    Solution.accountsMerge(self, accounts)
main()