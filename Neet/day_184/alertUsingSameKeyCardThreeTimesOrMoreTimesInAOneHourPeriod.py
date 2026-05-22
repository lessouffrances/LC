class Solution(object):
    def alertNames(self, keyName, keyTime):
        if not keyName or not keyTime:
            return []
        if len(keyName) != len(keyTime):
            return []

        self.access_record = {}
        n = len(keyName)
        
        for i in range(n):
            name, time  = keyName[i], keyTime[i]
            self.record(name, time)
        
        res = set()
        for name, records in self.access_record.items():
            records.sort()
            m = len(records)
            for i in range(2, m):
                if records[i]-records[i-2] <= 60:
                    res.add(name)

        lst = list(res)
        lst.sort()
        return lst

    def record(self, name, time):
        # process the time
        hour, minute = time.split(':')
        hour, minute = int(hour), int(minute)
        timestamp = hour * 60 + minute

        if name not in self.access_record:
            self.access_record[name] = []
        self.access_record[name].append(timestamp)
    