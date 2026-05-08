class Solution(object):
    def groupMessages(self, timeStamp, replyTo, messageText):
        if not timeStamp or not replyTo or not messageText:
            return []

        n = len(timeStamp)
        if len(replyTo) != n or len(messageText) != n:
            return []

        is_root = [False] * n
        for i in range(n):
            if replyTo[i] == -1:
                is_root[i] = True
            else:
                is_root[i] = False
        
        # find out the keys
        roots = [] # tuple(time, rootIdx)
        for i in range(n):
            if is_root[i]:
                roots.append( (timeStamp[i], i) )

        collector = {} # rootIdx : (time, msgText)
        for i in range(n):
            if is_root[i]:
                continue
            if replyTo[i] not in collector:
                collector[replyTo[i]] = []
            collector[replyTo[i]].append( (timeStamp[i], messageText[i]) )
        
        # sort and populate
        roots.sort()
        for _, info in collector.items():
            info.sort()

        res = []
        for _, rootIdx in roots:
            curr_group = []
            curr_group.append(messageText[rootIdx])
            for _, msg in collector[rootIdx]:
                curr_group.append(msg)
            res.append(curr_group)
        
        return res
            

def main():
    timeStamp = [102, 104, 100, 103, 101]
    replyTo = [-1, 0, -1, 2, 2]
    messageText = ["NewProjectUpdate", "GreatProgress", "MeetingAt3AM", "CanYouReschedule", "SoundsGood"]
    res = Solution().groupMessages(timeStamp, replyTo, messageText)
    print(res)
main()