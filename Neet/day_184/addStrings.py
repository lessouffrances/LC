class Solution(object):
    def addStrings(self, num1, num2):
        if not num1 and not num2: 
            return ""
        if not num1: 
            return num2
        if not num2:
            return num1
        
        i = len(num1)-1
        j = len(num2)-1
        carry = 0
        res = ""

        while i >= 0 or j >=0 or carry:
            sum = carry

            if i >= 0:
                sum += int(num1[i])
                i -= 1

            if j >= 0:
                sum += int(num2[j])
                j -= 1
            
            digit = sum % 10
            res = str(digit) + res
            carry = sum // 10
        
        return res
    