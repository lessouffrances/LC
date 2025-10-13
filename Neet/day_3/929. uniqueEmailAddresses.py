class Solution:
    def numUniqueEmails(self, emails: list[str]) -> int:
        unique = set()

        for e in emails:
            local, domain = e.split("@")
            local = local.split("+")[0]
            local = local.replace(".", "")
            # print((local, domain))
            unique.add((local, domain))
            # print(unique)
        print(len(unique))
        return len(unique)
            


def main():
    self = Solution()
    emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    Solution.numUniqueEmails(self, emails)

main()