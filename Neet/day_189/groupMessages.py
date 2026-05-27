class Solution(object):
    def groupMessages(self, timeStamp, replyTo, messageText):
        if not timeStamp or not replyTo or not messageText:
            return []
        n = len(timeStamp)
        if len(replyTo) != n or len(messageText) != n:
            return []
        
        # extract the root and sort by timestamps
        roots = [] # (timestamp, root_idx)
        for i in range(n):
            if replyTo[i] == -1:
                roots.append( (timeStamp[i], i) )
        roots.sort()

        # group the messages by rootIdx
        group_by_root_idx = {} # root_idx : (timestamp, msg)
        for i in range(n):
            if replyTo[i] == -1:
                continue
            else:
                if replyTo[i] not in group_by_root_idx:
                    group_by_root_idx[replyTo[i]] = []
                group_by_root_idx[replyTo[i]].append( (timeStamp[i], messageText[i]) )
        
        # populate the res based on root
        res = []
        for _, root_idx in roots:
            group = []
            group.append(messageText[root_idx])
            if root_idx in group_by_root_idx:
                group_by_root_idx[root_idx].sort()
            for _, msg in group_by_root_idx[root_idx]:
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