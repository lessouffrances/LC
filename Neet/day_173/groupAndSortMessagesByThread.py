class Solution(object):
    def groupMessages(self, timeStamp, replyTo, messageText):
        if len(timeStamp) == 0 or len(replyTo) == 0 or len(messageText) == 0:
            return []
        n = len(timeStamp)

        if len(replyTo) != n or len(messageText) != n:
            return []
        
        # mark root
        root = [0] * n 
        for i in range(n):
            if replyTo[i] == -1:
                root[i] = i
            else:
                root[i] = replyTo[i]
        
        keys = [] # { time, rootIdx }
        groups = {} # int : { {time, text} }

        # find keys and sort keys
        for i in range(n):
            if root[i] == i:
                keys.append( (timeStamp[i], root[i]) )
            else:
                if root[i] not in groups:
                    groups[root[i]] = []
                groups[root[i]].append( (timeStamp[i], messageText[i]) )
        

        # sort by time
        keys.sort()
        for _, msgs in groups.items():
            msgs.sort()
        
        # populate
        res = []
        for _, rootIdx in keys:
            group = []
            group.append(messageText[rootIdx])
            for _, msg in groups[rootIdx]:
                group.append(msg)
            res.append(group)

        return res


def main():
    timeStamp = [102, 104, 100, 103, 101]
    replyTo = [-1, 0, -1, 2, 2]
    messageText = ["NewProjectUpdate", "GreatProgress", "MeetingAt3AM", "CanYouReschedule", "SoundsGood"]
    res = Solution().groupMessages(timeStamp, replyTo, messageText)
    print(res)
main()