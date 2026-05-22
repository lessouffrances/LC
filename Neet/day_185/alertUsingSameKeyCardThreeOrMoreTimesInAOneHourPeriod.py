class Solution(object):
    def alertNames(self, keyName, keyTime):
        if not keyName or not keyTime:
            return []
        if len(keyName) != len(keyTime):
            return []

        n = len(keyTime)
        record = {} # { name : {} }
        for i in range(n):
            if keyName[i] not in record:
                record[keyName[i]] = []
            record[keyName[i]].append(self.processTime(keyTime[i]))
        
        name_set = set()
        for name, timestamps in record.items():
            timestamps.sort()
            m = len(timestamps)

            for j in range(2, m):
                if timestamps[j] - timestamps[j-2] <= 60:
                    name_set.add(name)
        
        res = list(name_set)
        res.sort()
        return res

    def processTime(self, time):
        hours, minutes = time.split(':')
        hours, minutes = int(hours), int(minutes)
        return hours * 60 + minutes