class Solution:
    def numUniqueEmails(self, emails) -> int:
        emailSet = set()

        for email in emails:
            local, domain = email.split("@")
            validLocal = local.split("+")[0]

            realLocal = ""
            for char in validLocal:
                if char != ".":
                    realLocal += char
                else:
                    continue

            realEmail = realLocal + "@" + domain
            emailSet.add(realEmail)
        
        return len(emailSet)
        



            
        
    

def main():
    self = Solution
    emails = ["test.email+alex@leetcode.com",
     "test.e.mail+bob.cathy@leetcode.com",
     "testemail+david@lee.tcode.com"]
    emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
    print(Solution.numUniqueEmails(self, emails))

main()