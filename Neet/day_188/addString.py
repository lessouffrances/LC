class Solution(object):
    def addStrings(self, num1, num2):
        if not num1:
            return num2
        if not num2:
            return num1
        
        i = len(num1)-1
        j = len(num2)-1

        res = ""
        carry = 0
        while i>=0 or j>=0 or carry:
            the_sum = carry
            if i>=0:
                the_sum += int(num1[i])
                i -= 1
            if j>=0: 
                the_sum += int(num2[j])
                j -= 1

            digit = the_sum % 10
            res = str(digit) + res
            carry = the_sum // 10
        return res

        