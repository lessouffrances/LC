class Solution(object):
    def alertNames(self, keyName, keyTime):
        if len(keyName) == 0:
            return []
        if len(keyName) != len(keyTime):
            return []
        n = len(keyName)

        record = {}
        for i in range(n):
            name, time = keyName[i], keyTime[i]
            if name not in record:
                record[name] = []
            record[name].append(self.processRecord(time))

        res = set()
        for name, records in record.items():
            records.sort()
            for i in range(2, len(records)):
                if records[i]-records[i-2] <= 60:
                    res.add(name)

        res_lst = list(res)
        res_lst.sort()
        return res_lst


    def processRecord(self, time):
        hours, minutes = time.split(':')
        hours = int(hours)
        minutes = int(minutes)
        return hours * 60 + minutes

        