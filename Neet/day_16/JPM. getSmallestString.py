def getSmallestString(word, substr):
    listWord = list(word)

    k = len(substr)
    for i in range(len(word)):
        if (i+k) < len(word):
            currStr = listWord[i:i+k]
            for j in range(len(currStr)):
                if listWord[j] == "?":
                    currStr[j] = substr[j]
            if "".join(currStr) == substr:
                listWord[i:i+k] = substr
                for i in range(len(word)):
                    if listWord[i] == "?":
                        listWord[i] == "a"
    if "?" in set(listWord):
        return "-1"
    else:
        word = "".join(listWord)
        return word