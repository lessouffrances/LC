class Solution(object):
    def groupMessages(self, timeStamp, replyTo, messageText):
        if not timeStamp or not replyTo or not messageText:
            return []
        n = len(timeStamp)
        if len(replyTo) != n or len(messageText) != n:
            return []
        
        # sort out the roots
        is_root = [False] * n
        roots_with_idx = [] # ( time, rootIdx )
        for i in range(n):
            if replyTo[i] == -1:
                is_root[i] = True
                roots_with_idx.append( (timeStamp[i], i) ) 
        
        # construct the groups
        groups = {} # rootIdx, [ (time, msg) ]
        for i in range(n):
            if is_root[i]:
                continue
            if replyTo[i] not in groups:
                groups[replyTo[i]] = []
            groups[replyTo[i]].append( ( timeStamp[i], messageText[i] ) )
        
        # sort and populate the res
        res = []
        for _, root_idx in roots_with_idx:
            group = []
            group.append(messageText[root_idx])
            if root_idx in groups:
                groups[root_idx].sort()
                for _, msg in groups[root_idx]:
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
