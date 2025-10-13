hashMap = {(-1, 2, 1): 1, (2, 1, -4): 2, (-1, 2, -4): 4, (-1, 1, -4): 5}

# A small forloop
def getKeyByVal_1(dict, value):
    for key, val in dict.items():
        if val == value:
            return key
    return None  # not found

# Dictionary Comprehension
def getKeyByVal_2(dict, value):
    return next((k for k, v in dict.items() if v == value), None)






