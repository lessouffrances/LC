class Solution:
    def numUniqueEmails(self, emails: list[str]) -> int:
        hashSet = set()
        for e in emails:
            local, domain = e.split("@")
            local = local.split("+")[0]
            local = local.replace(".", "")

            # print(local, domain)
            hashSet.add((local, domain))
        return len(hashSet)
              

def main():
    self = Solution()
    emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    print(Solution.numUniqueEmails(self, emails))
main()